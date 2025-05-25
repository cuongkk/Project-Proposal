#ifndef PRODUCTREPOSITORY_H
#define PRODUCTREPOSITORY_H

#include "Repository.h"
#include "../models/Main_all.h"
#include "ProductQueryBuilder.h"
#include <mysql/jdbc.h>

class ProductRepositoryImpl : public IRepository
{
private:
    sql::mysql::MySQL_Driver *driver;
    std::shared_ptr<sql::Connection> conn;
    LinkedList<Product> _products;
    ProductQueryBuilder productQueryBuilder;

public:
    ProductRepositoryImpl(const std::string &,
                          const std::string &,
                          const std::string &,
                          const std::string &);

    void set_products(const std::shared_ptr<sql::ResultSet> &);

    void loadFromDatabase() override;
    const LinkedList<Product> &getAll();

    void insert(const std::vector<std::string> &);

    void filter(const std::string &, const std::string &,
                const std::string &, const std::string &, const std::string &);
};

#endif
