#ifndef USER_H
#define USER_H

#include <string>
class User
{
protected:
    int _id;
    std::string _username;
    std::string _password;

public:
    User();
    ~User();
    User(const int &, const std::string &, const std::string &);
};

#endif