#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "../models/Main_all.h"
class IRepository
{
public:
    virtual ~IRepository() = default;
    virtual void loadFromDatabase() = 0;
    virtual void insert(const std::vector<std::string> &fields) = 0;
    virtual void deleteByID(const std::string &id) = 0;
    virtual void update(const std::vector<std::string> &fields) = 0;
};

#endif