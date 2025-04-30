#include "Customer.h"

Customer::Customer() : User()
{
    _name = "";
    _email = "";
    _phoneNumber = "";
    _money = "";
}

Customer::~Customer() = default;

Customer::Customer(const std::string &name, const std::string &email,
                   const std::string &phoneNumber, const std::string &money,
                   const std::string &username, const std::string &password, const std::string &inf)
    : User(username, password, inf)
{
    _name = name;
    _email = email;
    _phoneNumber = phoneNumber;
    _money = money;
}

std::unique_ptr<User> Customer::clone() const
{
    auto cloned = std::make_unique<Customer>(*this);
    auto nonconst_this = const_cast<Customer *>(this);
    cloned->_origin = static_cast<User *>(nonconst_this);
    return cloned;
}

User *Customer::get_origin() const
{
    return _origin;
}

void Customer::print(std::ostream &os) const
{
    os << _id << ", ";
    os << _username << ", ";
    os << _password << ", ";
    os << _inf << ", ";
    os << _name << ", ";
    os << _email << ", ";
    os << _phoneNumber << ", ";
    os << _money;
}