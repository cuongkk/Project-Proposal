#include "Food.h"

Food::Food() : Product()
{
    _name = "";
    _inf = "";
}

Food::~Food()
{
}

Food::Food(const std::string &id_sp, const std::string &name, const std::string &inf,
           const int &quantity, const std::string &money,
           const float &discount,
           const DateTime &manufacture_Date, const DateTime &expiry_Date,
           const std::string &imagePath)
    : Product(id_sp, quantity, money, discount, manufacture_Date, expiry_Date, imagePath)
{
    _name = name;
    _inf = inf;
}

std::unique_ptr<Product> Food::clone() const
{
    auto cloned = std::make_unique<Food>(*this);
    auto nonconst_this = const_cast<Food *>(this);
    cloned->_origin = static_cast<Product *>(nonconst_this);
    return cloned;
}

Product *Food::get_origin()
{
    return _origin;
}

std::string Food::get_name() const
{
    return _name;
}

std::string Food::get_inf() const
{
    return _inf;
}

std::string Food::get_type() const
{
    return "Đồ ăn";
}

void Food::print(std::ostream &os) const
{
    os << _name << ", ";
    os << _inf << ", ";
    os << _quantity << ", ";
    os << _money << ", ";
    os << _discount << ", ";
    os << _manufacture_Date << ", ";
    os << _expiry_Date;
}

std::ostream &operator<<(std::ostream &os, const Food &Food)
{
    return os;
}