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

void ProductRepositoryImpl::set_products(const std::shared_ptr<sql::ResultSet> &res)
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

void ProductRepositoryImpl::loadFromDatabase()
{
    _products.clear();

    std::shared_ptr<sql::Statement> stmt(conn->createStatement());
    std::shared_ptr<sql::ResultSet> res(
        stmt->executeQuery("SELECT id, name, inf, category, price, discount, quantity, manufacture_date, expiry_date, image_path FROM Products"));

    while (res->next())
    {
        set_products(res);
    }
}

const LinkedList<Product> &ProductRepositoryImpl::getAll()
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

void ProductRepositoryImpl::filter(const std::string &id, const std::string &name,
                                   const std::string &category, const std::string &minPrice, const std::string &maxPrice)
{
    _products.clear();

    productQueryBuilder.filterById(id)
        .filterByName(name)
        .filterByCategory(category)
        .filterByPriceRange(minPrice, maxPrice);

    std::shared_ptr<sql::Statement> stmt(conn->createStatement());
    std::shared_ptr<sql::ResultSet> res(
        stmt->executeQuery(productQueryBuilder.buildFilter()));

    while (res->next())
    {
        set_products(res);
    }
}

void ProductRepositoryImpl::update(const std::string &id, const std::string &name,
                                   const std::string &inf, const std::string &price,
                                   const std::string &discount, const std::string &quantity,
                                   const std::string &manufactureDate, const std::string &expiryDate,
                                   const std::string &imagePath)
{
    productQueryBuilder.updateName(name)
        .updateInf(inf)
        .updatePrice(price)
        .updateDiscount(discount)
        .updateQuantity(quantity)
        .updateManufactureDate(manufactureDate)
        .updateExpiryDate(expiryDate)
        .updateImagePath(imagePath);

    std::shared_ptr<sql::PreparedStatement> pstmt(conn->prepareStatement(
        productQueryBuilder.buildUpdate() + " WHERE id = ?"));

    pstmt->setString(1, id);
    pstmt->executeUpdate();
}

void ProductRepositoryImpl::remove(const std::string &id)
{
    std::shared_ptr<sql::PreparedStatement> pstmt(conn->prepareStatement(
        "DELETE FROM Products WHERE id = ?"));
    pstmt->setString(1, id);
    pstmt->executeUpdate();
}