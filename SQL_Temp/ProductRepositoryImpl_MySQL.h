#pragma once
#include "ProductRepository.h"
#include <mysql/jdbc.h>
#include <iostream>
#include <memory>

class ProductRepositoryImpl_MySQL : public ProductRepository {
private:
    sql::mysql::MySQL_Driver* driver;
    std::unique_ptr<sql::Connection> conn;

public:
    ProductRepositoryImpl_MySQL(const std::string& host,
                                const std::string& user,
                                const std::string& pass,
                                const std::string& db) {
        driver = sql::mysql::get_mysql_driver_instance();
        conn.reset(driver->connect(host, user, pass));
        conn->setSchema(db);
    }

    std::vector<Product> getProducts(const std::string& query) override {
        std::vector<Product> result;
        std::unique_ptr<sql::Statement> stmt(conn->createStatement());
        std::unique_ptr<sql::ResultSet> res(stmt->executeQuery(query));

        while (res->next()) {
            std::string id = res->getString("id");
            std::string name = res->getString("name");
            double price = res->getDouble("price");
            std::string category = res->getString("category");

            result.emplace_back(id, name, price, category);
        }

        return result;
    }
};
