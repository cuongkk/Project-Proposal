#ifndef USERMANAGEMENT_H
#define USERMANAGEMENT_H

#include "Main.h"
#include "User.h"
#include "LinkedList.h"
class UserManagement
{
private:
    LinkedList<User> _user;

public:
    UserManagement() = default;
    ~UserManagement() = default;

    void add(std::unique_ptr<User>);
    void remove(std::unique_ptr<User>);
    std::unique_ptr<User> getUser_from_id(const std::string &);
    bool containsKeyword(const std::string &, const int&, const User&) const;
    std::vector<std::string> search(const std::string &, const int &);
    friend std::ostream &operator<<(std::ostream &, const UserManagement &);
};
#endif