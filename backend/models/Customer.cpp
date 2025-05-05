#include "Customer.h"

Customer::Customer() : User()
{
    _name = "";
    _email = "";
    _phoneNumber = "";
    Money _money;
}

Customer::~Customer() = default;

Customer::Customer(const std::string &username,
                   const std::string &password, const std::string &name) : User(username, password, name)

{
}
Customer::Customer(const std::string &fullname, const std::string &email,
                   const std::string &phoneNumber, const std::string &money,
                   const std::string &type, const std::string &username,
                   const std::string &password, const std::string &name)
    : User(username, password, name)
{
    _fullname = fullname;
    _email = email;
    _phoneNumber = phoneNumber;
    _money = Money(money, type);
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

std::string Customer::get_money() const
{
    return _money.get_money();
}

void Customer::set_money(const std::string &money)
{
    _money.set_money(money);
}

void Customer::print(std::ostream &os) const
{
    os << _id_user << ", ";
    os << _username << ", ";
    os << _password << ", ";
    os << _name << ", ";
    os << _name << ", ";
    os << _email << ", ";
    os << _phoneNumber << ", ";
    os << _money;
}