#include "User.h"

User::User()
{
    _username = "";
    _password = "";
    _name = "";
}

User::User(const std::string &id_user, const std::string &username,
           const std::string &password, const std::string &name)
    : _id_user(id_user), _username(username), _password(password), _name(name)
{
}

std::string User::get_id() const
{
    return _id_user;
}

void User::set_username(const std::string &username)
{
    _username = username;
}

std::string User::get_username() const
{
    return _username;
}

void User::set_password(const std::string &password)
{
    _password = password;
}

std::string User::get_password() const
{
    return _password;
}

void User::set_name(const std::string &name)
{
    _name = name;
}

std::string User::get_name() const
{
    return _name;
}

std::string operator-(const std::shared_ptr<User> &a, const std::string &b)
{
    long long result = std::stoll(a->get_money()) - std::stoll(b);
    return std::to_string(result);
}

bool operator<=(const std::shared_ptr<User> &a, const long long &b)
{
    return std::stoll(a->get_money()) <= b;
}

bool operator>=(const std::shared_ptr<User> &a, const long long &b)
{
    return std::stoll(a->get_money()) >= b;
}

bool operator==(const User &a, const User &b)
{
    return a.get_id() == b.get_id();
}

std::ostream &operator<<(std::ostream &os, const User &user)
{
    user.print(os);
    return os;
}
