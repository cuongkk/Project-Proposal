#include "Customer.h"

Customer::Customer() : User()
{
    _name = "";
    _email = "";
    _phoneNumber = "";
    Money _money;
}

Customer::~Customer() = default;

Customer::Customer(const std::string &id_user, const std::string &username,
                   const std::string &password, const std::string &name)
    : User(id_user, username, password, name)
{
}
Customer::Customer(const std::string &id_user, const std::string &username,
                   const std::string &password, const std::string &name,
                   const std::string &fullname, const std::string &email,
                   const std::string &phoneNumber, const std::string &money)
    : User(id_user, username, password, name), _fullname(fullname), _email(email),
      _phoneNumber(phoneNumber), _money(money)
{
}

std::shared_ptr<User> Customer::clone() const
{
    auto cloned = std::make_shared<Customer>(*this);
    auto nonconst_this = const_cast<Customer *>(this);
    cloned->_origin = static_cast<User *>(nonconst_this);
    return cloned;
}

User *Customer::get_origin() const
{
    return _origin;
}

void Customer::set_fullname(const std::string &fullname)
{
    _fullname = fullname;
}

std::string Customer::get_fullname() const
{
    return _fullname;
}

void Customer::set_email(const std::string &email)
{
    _email = email;
}

std::string Customer::get_email() const
{
    return _email;
}

void Customer::set_phoneNumber(const std::string &phoneNumber)
{
    _phoneNumber = phoneNumber;
}

std::string Customer::get_phoneNumber() const
{
    return _phoneNumber;
}

void Customer::set_money(const std::string &money)
{
    _money.set_value(money);
    _money.set_type("VND");
}

std::string Customer::get_money() const
{
    return _money.get_value();
}

Cart Customer::get_cart() const
{
    return _cart;
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