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
        }
    }

    LinkedList<Product> &getAll() override
    {
        return _products;
    }

    // Các hàm thêm, xóa, cập nhật bạn có thể mở rộng tương tự
};

#endif
