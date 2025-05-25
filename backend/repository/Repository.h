#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "../models/Main_all.h"
class IRepository
{
public:
    virtual ~IRepository() = default;
    virtual void loadFromDatabase() = 0;
};

#endif