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
    static std::vector<int> _id_counter_user;

    UserManagement() = default;
    ~UserManagement() = default;

    void add(std::shared_ptr<User>);
    void remove(std::shared_ptr<User>);
    std::vector<std::string> get_username_user() const;
    std::vector<std::string> get_name_user() const;
    std::vector<std::string> get_email_user() const;
    std::vector<std::string> get_phoneNumber_user() const;

    std::shared_ptr<User> getUser_from_id(const std::string &);
    void clear();
    // bool containsKeyword(const std::string &, const int &, const User &) const;
    // std::vector<std::string> search(const std::string &, const int &);
    friend std::ostream &operator<<(std::ostream &, const UserManagement &);
};
#endif