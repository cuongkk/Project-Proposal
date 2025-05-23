#include "Drink.h"

Drink::Drink() : Product()
{
    _name = "";
    _inf = "";
}

Drink::~Drink()
{
}

Drink::Drink(const std::string &id_sp, const std::string &name, const std::string &inf,
             const int &quantity, const std::string &money,
             const std::string &discount,
             const DateTime &manufacture_Date, const DateTime &expiry_Date,
             const std::string &imagePath)
    : Product(id_sp, quantity, money, discount, manufacture_Date, expiry_Date, imagePath)
{
    _name = name;
    _inf = inf;
}

std::unique_ptr<Product> Drink::clone() const
{
    auto cloned = std::make_unique<Drink>(*this);
    auto nonconst_this = const_cast<Drink *>(this);
    cloned->_origin = static_cast<Product *>(nonconst_this);
    return cloned;
}

Product *Drink::get_origin()
{
    return _origin;
}

std::string Drink::get_name() const
{
    return _name;
}

std::string Drink::get_inf() const
{
    return _inf;
}

void Drink::print(std::ostream &os) const
{
    os << _name << ", ";
    os << _inf << ", ";
    os << _quantity << ", ";
    os << _money << ", ";
    os << _discount << ", ";
    os << _manufacture_Date << ", ";
    os << _expiry_Date;
}

std::ostream &operator<<(std::ostream &os, const Drink &Drink)
{

    return os;
}