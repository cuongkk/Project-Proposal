#ifndef BILLREPOSITORY_H
#define BILLREPOSITORY_H

#include "Repository.h"
#include "BillQueryBuilder.h"
#include "../models/Main_all.h"
#include <mysql/jdbc.h>
class BillRepositoryImpl : public IRepository
{
private:
    sql::mysql::MySQL_Driver *driver;
    std::shared_ptr<sql::Connection> conn;
    LinkedList<Bill> _bills;
    BillQueryBuilder billQueryBuilder;

public:
    BillRepositoryImpl(const std::string &,
                       const std::string &,
                       const std::string &,
                       const std::string &);

    void set_bills(const std::shared_ptr<sql::ResultSet> &);

    void loadFromDatabase() override;
    const LinkedList<Bill> &getAll();

    void insert(const std::vector<std::string> &, const LinkedList<Product> &);

    void filter(const std::string &, const std::string &,
                const std::string &, const std::string &);

    void filterCart(std::string &);
    void updateCart(const std::string &, const std::string &,
                    const int &, const std::string &);
    void deleteCart(const std::string &, const std::string &);
};
#endif