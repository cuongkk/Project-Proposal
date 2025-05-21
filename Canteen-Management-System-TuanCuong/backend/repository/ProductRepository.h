#ifndef PRODUCTREPOSITORY_H
#define PRODUCTREPOSITORY_H

#include "../models/Main_all.h"
#include <mysql/jdbc.h>
class IRepository
{
public:
    virtual ~IRepository() = default;
    virtual void loadFromDatabase() = 0; // THÊM HÀM MỚI
    virtual LinkedList<Product> &getAll() = 0;
};

class ProductRepositoryImpl : public IRepository
{
private:
    sql::mysql::MySQL_Driver *driver;
    std::unique_ptr<sql::Connection> conn;
    LinkedList<Product> _products;

public:
    ProductRepositoryImpl(const std::string &host,
                          const std::string &user,
                          const std::string &pass,
                          const std::string &db)
    {
        driver = sql::mysql::get_mysql_driver_instance();
        conn.reset(driver->connect(host, user, pass));
        conn->setSchema(db);
        conn->setClientOption("CHARSET", "utf8mb4");
    }

    void loadFromDatabase() override
    {
        _products.clear();

        std::unique_ptr<sql::Statement> stmt(conn->createStatement());
        std::unique_ptr<sql::ResultSet> res(
            stmt->executeQuery("SELECT id, name, inf, type, price, discount, quantity, manufacture_date, expiry_date, image_path FROM Products"));

        while (res->next())
        {
            if (res->getString("type") == "Đồ uống")
            {
                auto product = std::make_unique<Drink>(
                    res->getString("id"),
                    res->getString("name"),
                    res->getString("inf"),
                    res->getInt("quantity"),
                    std::to_string(res->getDouble("price")),
                    res->getDouble("discount"),
                    DateTime(res->getString("manufacture_date")),
                    DateTime(res->getString("expiry_date")),
                    res->getString("image_path"));
                _products.push_back(std::move(product));
            }
            else if (res->getString("type") == "Đồ ăn")
            {
                auto product = std::make_unique<Food>( 
                    res->getString("id"),
                    res->getString("name"),
                    res->getString("inf"),
                    res->getInt("quantity"),
                    std::to_string(res->getDouble("price")),
                    res->getDouble("discount"),
                    DateTime(res->getString("manufacture_date")),
                    DateTime(res->getString("expiry_date")),
                    res->getString("image_path"));
                _products.push_back(std::move(product));
            }
        }
    }

    LinkedList<Product> &getAll() override
    {
        return _products;
    }

    //void insertProduct(const std::vector<std::string> &fields);
    void insertProduct(const std::vector<std::string> &fields)
    {
        if (fields.size() != 10)
        {
            throw std::invalid_argument("Không đủ số lượng trường cho sản phẩm (cần 10).");
        }

        std::unique_ptr<sql::PreparedStatement> pstmt(conn->prepareStatement(
            "INSERT INTO Products (id, name, inf, type, price, discount, quantity, manufacture_date, expiry_date, image_path) "
            "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)"));

        pstmt->setString(1, fields[0]);                       // id
        pstmt->setString(2, fields[1]);                       // name
        pstmt->setString(3, fields[2]);                       // inf
        pstmt->setString(4, fields[3]);                       // type
        pstmt->setDouble(5, std::stod(fields[4]));            // price
        pstmt->setDouble(6, std::stod(fields[5]));            // discount
        pstmt->setInt(7, std::stoi(fields[6]));               // quantity
        pstmt->setString(8, fields[7]);                       // manufacture_date
        pstmt->setString(9, fields[8]);                       // expiry_date
        pstmt->setString(10, fields[9]);                      // image_path

        pstmt->executeUpdate();
    }
        // bool deleteProductById(const std::string &id);

};





#endif