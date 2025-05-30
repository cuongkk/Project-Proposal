#include "UserRepository.h"

UserRepositoryImpl::UserRepositoryImpl(const std::string &host,
                                       const std::string &user,
                                       const std::string &pass,
                                       const std::string &db)
{
    driver = sql::mysql::get_mysql_driver_instance();
    conn.reset(driver->connect(host, user, pass));
    conn->setSchema(db);
    conn->setClientOption("CHARSET", "utf8mb4");
}

void UserRepositoryImpl::set_users(const std::shared_ptr<sql::ResultSet> &res)
{
    std::string username = res->getString("username");

    if (username.compare("admin") == 0)
    {
        auto user = std::make_shared<Admin>(
            res->getString("id"),
            res->getString("username"),
            res->getString("password"),
            res->getString("name"),
            res->getString("image_path"));
        _users.push_back(user);
    }
    else
    {
        auto user = std::make_shared<Customer>(
            res->getString("id"),
            res->getString("username"),
            res->getString("password"),
            res->getString("name"),
            res->getString("image_path"),
            res->getString("fullname"),
            res->getString("email"),
            res->getString("phoneNumber"),
            std::to_string(res->getInt("money")));
        _users.push_back(user);
    }
}
void UserRepositoryImpl::loadFromDatabase()
{
    _users.clear();

    std::shared_ptr<sql::Statement> stmt(conn->createStatement());
    std::shared_ptr<sql::ResultSet> res(
        stmt->executeQuery("SELECT id, username, password, name, fullname, email, phoneNumber, money, image_path FROM User"));
    while (res->next())
    {
        set_users(res);
    }
}

const LinkedList<User> &UserRepositoryImpl::getAll()
{
    return _users;
}

void UserRepositoryImpl::filter(const std::string &id, const std::string &username,
                                const std::string &password, const std::string &name,
                                const std::string &email, const std::string &phoneNumber)
{
    _users.clear();

    userQueryBuilder.filterById(id)
        .filterByUsername(username)
        .filterByPassword(password)
        .filterByName(name)
        .filterByEmail(email)
        .filterByPhoneNumber(phoneNumber);
    std::shared_ptr<sql::Statement> stmt(conn->createStatement());
    std::shared_ptr<sql::ResultSet> res(
        stmt->executeQuery(userQueryBuilder.buildFilter()));
    while (res->next())
    {
        set_users(res);
    }
}

void UserRepositoryImpl::insert(const std::vector<std::string> &fields)
{
    if (fields.size() != 5)
    {
        throw std::invalid_argument("Không đủ số lượng trường cho sản phẩm (cần 4).");
    }

    std::shared_ptr<sql::PreparedStatement> pstmt(conn->prepareStatement(
        "INSERT INTO User (id, username, password, name, image_path) "
        "VALUES (?, ?, ?, ?, ?)"));

    pstmt->setString(1, fields[0]); // id
    pstmt->setString(2, fields[1]); // username
    pstmt->setString(3, fields[2]); // password
    pstmt->setString(4, fields[3]); // name
    pstmt->setString(5, fields[4]); // image_path

    pstmt->executeUpdate();
}

void UserRepositoryImpl::update(const std::string &id, const std::string &fullname,
                                const std::string &email, const std::string &phoneNumber,
                                const std::string &money, const std::string &image)
{
    userQueryBuilder.updateFullname(fullname)
        .updateEmail(email)
        .updatePhoneNumber(phoneNumber)
        .updateMoney(money)
        .updateImage(image);
    std::shared_ptr<sql::PreparedStatement> pstmt(conn->prepareStatement(
        userQueryBuilder.buildUpdate() + " WHERE id = ?"));

    pstmt->setString(1, id); // id

    pstmt->executeUpdate();
}
