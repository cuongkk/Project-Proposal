#include "User.h"

User::User()
{
    _username = "";
    _password = "";
    _inf = "";
}
User::User(const std::string &username, const std::string &password, const std::string &inf)
{
    _id = set_id("US", _id_counter_user);
    _username = username;
    _password = password;
    _inf = inf;
}

void User::set_counter(const int &index)
{
    _id_counter_user[index] = 0;
}

std::string User::get_id() const
{
    return _id;
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

void User::set_inf(const std::string &inf)
{
    _inf = inf;
}

std::string User::get_inf() const
{
    return _inf;
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
