#ifndef PRODUCTREPOSITORY_H
#define PRODUCTREPOSITORY_H

#include "Repository.h"
#include "../models/Main_all.h"
#include <mysql/jdbc.h>

class ProductRepositoryImpl : public IRepository
{
private:
    sql::mysql::MySQL_Driver *driver;
    std::shared_ptr<sql::Connection> conn;
    LinkedList<Product> _products;

public:
    ProductRepositoryImpl(const std::string &,
                          const std::string &,
                          const std::string &,
                          const std::string &);

    void loadFromDatabase() override;
    LinkedList<Product> &getAll();

    void insert(const std::vector<std::string> &fields) override;
    void deleteByID(const std::string &id) override;
    void update(const std::vector<std::string> &fields) override;
};

#endif
