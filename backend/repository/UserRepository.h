#ifndef USERREPOSITORY_H
#define USERREPOSITORY_H

#include "Repository.h"
#include "UserQueryBuilder.h"
#include "../models/Main_all.h"
#include <mysql/jdbc.h>
class UserRepositoryImpl : public IRepository
{
private:
    sql::mysql::MySQL_Driver *driver;
    std::shared_ptr<sql::Connection> conn;
    LinkedList<User> _users;
    UserQueryBuilder userQueryBuilder;

public:
    UserRepositoryImpl(const std::string &,
                       const std::string &,
                       const std::string &,
                       const std::string &);

    void set_users(const std::shared_ptr<sql::ResultSet> &);
    void loadFromDatabase() override;
    const LinkedList<User> &getAll();

    void insert(const std::vector<std::string> &fields);

    void filter(const std::string &, const std::string &,
                const std::string &, const std::string &,
                const std::string &, const std::string &);

    void update(const std::string &, const std::string &,
                const std::string &, const std::string &,
                const std::string &, const std::string &);

    // void select_name(const std::string &) override;
    // void select_category(const std::string &) override {};
    // void select_price(const std::string &, const std::string &) override {};
};

#endif
