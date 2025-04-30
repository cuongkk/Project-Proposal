#ifndef USERMANAGEMENT_H
#define USERMANAGEMENT_H

#include "User.h"
#include "LinkedList.h"
#include <memory>

class UserManagement
{
private:
    LinkedList<User> _user;

public:
    UserManagement() = default;
    ~UserManagement() = default;

    void add(std::unique_ptr<User>);
    void remove(std::unique_ptr<User>);
    void updateUser(const User &, const int &);
    std::unique_ptr<User> getUser_from_id(const std::string &);
    friend std::ostream &operator<<(std::ostream &, const UserManagement &);
};
#endif