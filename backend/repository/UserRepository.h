#ifndef USERREPOSITORY_H
#define USERREPOSITORY_H

#include "Repository.h"
#include "../models/Main_all.h"
#include <mysql/jdbc.h>
class UserRepositoryImpl : public IRepository
{
private:
    sql::mysql::MySQL_Driver *driver;
    std::shared_ptr<sql::Connection> conn;
    LinkedList<User> _user;

public:
    UserRepositoryImpl(const std::string &,
                       const std::string &,
                       const std::string &,
                       const std::string &);

    void loadFromDatabase() override;
    LinkedList<User> &getAll();

    void insert(const std::vector<std::string> &fields) override;
};

#endif
