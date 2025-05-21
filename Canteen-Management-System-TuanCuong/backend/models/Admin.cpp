#include "Admin.h"

Admin::Admin() : User()
{
}

Admin::~Admin()
{
}
Admin::Admin(const std::string &username, const std::string &password, const std::string &inf)
    : User(username, password, inf)
{
}

std::unique_ptr<User> Admin::clone() const
{
    auto cloned = std::make_unique<Admin>(*this);
    auto nonconst_this = const_cast<Admin *>(this);
    cloned->_origin = static_cast<User *>(nonconst_this);
    return cloned;
}

User *Admin::get_origin() const
{
    return _origin;
}

void Admin::set_fullname(const std::string &fullname)
{
}

std::string Admin::get_fullname() const
{
    return "";
}

void Admin::set_email(const std::string &email)
{
}

std::string Admin::get_email() const
{
    return "";
}

void Admin::set_phoneNumber(const std::string &phoneNumber)
{
}

std::string Admin::get_phoneNumber() const
{
    return "";
}

void Admin::set_money(const std::string &money)
{
}

std::string Admin::get_money() const
{
    return "";
}

Cart Admin::get_cart() const
{
    return _cart;
}

void Admin::print(std::ostream &os) const
{
    os << _id_user << ", ";
    os << _username << ", ";
    os << _password << ", ";
    os << _name;
}
