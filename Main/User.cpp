#include "User.h"

User::User()
{
    _id = 0;
    _username = "";
    _password = "";
}
User::~User()
{
}
User::User(const int &id, const std::string &user_Name, const std::string &password)
{
    _id = id;
    _username = user_Name;
    _password = password;
}