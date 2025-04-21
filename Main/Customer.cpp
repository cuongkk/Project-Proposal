#include "Customer.h"

Customer::Customer() : User()
{
    _name = "";
    _email = "";
    _phone_Number = "";
    _money = 0;
}

Customer::Customer(const std::string name, const std::string email,
                   const std::string phone_Number, const int &money,
                   const int &id, const std::string &username, const std::string &password)
    : User(id, username, password)
{
    _name = name;
    _email = email;
    _phone_Number = phone_Number;
    _money = money;
}
