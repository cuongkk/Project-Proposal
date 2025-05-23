#include "Repository.h"
#include "ProductRepository.h"

ProductRepositoryImpl::ProductRepositoryImpl(const std::string &host,
                                             const std::string &user,
                                             const std::string &pass,
                                             const std::string &db)
{
    driver = sql::mysql::get_mysql_driver_instance();
    conn.reset(driver->connect(host, user, pass));
    conn->setSchema(db);
    conn->setClientOption("CHARSET", "utf8mb4");
}

void ProductRepositoryImpl::loadFromDatabase()
{
    _products.clear();

    std::shared_ptr<sql::Statement> stmt(conn->createStatement());
    std::shared_ptr<sql::ResultSet> res(
        stmt->executeQuery("SELECT id, name, inf, category, price, discount, quantity, manufacture_date, expiry_date, image_path FROM Products"));

    while (res->next())
    {
        std::string category = res->getString("category");
        std::string DoAn = "Đồ ăn";
        std::string DoUong = "Đồ uống";
        if (category.compare(DoUong) == 0)
        {
            auto product = std::make_shared<Drink>(
                res->getString("id"),
                res->getString("name"),
                res->getString("inf"),
                res->getInt("quantity"),
                std::to_string(res->getInt("price")),
                std::to_string(res->getInt("discount")),
                DateTime(res->getString("manufacture_date")),
                DateTime(res->getString("expiry_date")),
                res->getString("image_path"));
            _products.push_back(product);
        }
        else if (category.compare(DoAn) == 0)
        {
            auto product = std::make_shared<Food>(
                res->getString("id"),
                res->getString("name"),
                res->getString("inf"),
                res->getInt("quantity"),
                std::to_string(res->getInt("price")),
                std::to_string(res->getInt("discount")),
                DateTime(res->getString("manufacture_date")),
                DateTime(res->getString("expiry_date")),
                res->getString("image_path"));
            _products.push_back(product);
        }
    }
}

LinkedList<Product> &ProductRepositoryImpl::getAll()
{
    return _products;
}

void ProductRepositoryImpl::insert(const std::vector<std::string> &fields)
{
    if (fields.size() != 10)
    {
        throw std::invalid_argument("Không đủ số lượng trường cho sản phẩm (cần 10).");
    }

    std::shared_ptr<sql::PreparedStatement> pstmt(conn->prepareStatement(
        "INSERT INTO Products (id, name, inf, category, price, discount, quantity, manufacture_date, expiry_date, image_path) "
        "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)"));

    pstmt->setString(1, fields[0]);         // id
    pstmt->setString(2, fields[1]);         // name
    pstmt->setString(3, fields[2]);         // inf
    pstmt->setString(4, fields[3]);         // category
    pstmt->setInt(5, std::stoi(fields[4])); // price
    pstmt->setInt(6, std::stoi(fields[5])); // discount
    pstmt->setInt(7, std::stoi(fields[6])); // quantity
    pstmt->setString(8, fields[7]);         // manufacture_date
    pstmt->setString(9, fields[8]);         // expiry_date
    pstmt->setString(10, fields[9]);        // image_path

    pstmt->executeUpdate();
}

void ProductRepositoryImpl::deleteByID(const std::string &id)
{
    try
    {
        std::unique_ptr<sql::PreparedStatement> pstmt(
            conn->prepareStatement("DELETE FROM Products WHERE id = ?"));
            pstmt->setString(1, id);
            int rowsAffected = pstmt->executeUpdate();

            std::cout << "[INFO] Đã xóa " << rowsAffected << " sản phẩm có ID = " << id << "\n";
            if (rowsAffected == 0)
            {
                std::cout << "[INFO] Không tìm thấy sản phẩm có ID = " << id << "\n";
            }
    }
    catch (const sql::SQLException &e)
    {
        std::cerr << "[MySQL ERROR] Xóa thất bại: " << e.what() << " (code: " << e.getErrorCode() << ")\n";
    }
}

void ProductRepositoryImpl::update(const std::vector<std::string> &fields)
{
    if (fields.size() != 10)
    {
        std::cerr << "[ERROR] Thiếu trường khi cập nhật sản phẩm.\n";
        return;
    }

    try
    {
        std::unique_ptr<sql::PreparedStatement> pstmt(
            conn->prepareStatement("UPDATE Products SET name = ?, inf = ?, type = ?, price = ?, discount = ?, quantity = ?, manufacture_date = ?, expiry_date = ?, image_path = ? WHERE id = ?"));

        pstmt->setString(1, fields[1]); // name
        pstmt->setString(2, fields[2]); // inf
        pstmt->setString(3, fields[3]); // type
        pstmt->setDouble(4, std::stod(fields[4])); // price
        pstmt->setDouble(5, std::stod(fields[5])); // discount
        pstmt->setInt(6, std::stoi(fields[6])); // quantity
        pstmt->setString(7, fields[7]); // manufacture_date
        pstmt->setString(8, fields[8]); // expiry_date
        pstmt->setString(9, fields[9]); // image_path
        pstmt->setString(10, fields[0]); // id WHERE 

        int rowsAffected = pstmt->executeUpdate();
        std::cout << "[INFO] Đã cập nhật " << rowsAffected << " sản phẩm có ID = " << fields[0] << "\n";

        if (rowsAffected == 0)
        {
            std::cout << "[INFO] Không tìm thấy sản phẩm có ID = " << fields[0] << "\n";
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "[ERROR] Cập nhật thất bại: " << e.what() << "\n";
    }
}

