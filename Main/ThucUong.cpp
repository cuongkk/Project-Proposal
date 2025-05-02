#include "ThucUong.h"

ThucUong::ThucUong() : SanPham()
{
    _name = "";
    _inf = "";
}

ThucUong::~ThucUong() // Định nghĩa Destructor
{
}

ThucUong::ThucUong(const std::string &name, const std::string &inf,
                   const std::string &type, const int &quantity, const std::string &money,
                   const std::string &type_money, const float &discount,
                   const std::string &manufacture_Date, const std::string &expiry_Date)
    : SanPham(type, quantity, money, type_money, discount, manufacture_Date, expiry_Date)
{
    _name = name;
    _inf = inf;
}

std::unique_ptr<SanPham> ThucUong::clone() const
{
    auto cloned = std::make_unique<ThucUong>(*this);
    auto nonconst_this = const_cast<ThucUong *>(this);
    cloned->_origin = static_cast<SanPham *>(nonconst_this);
    return cloned;
}

SanPham *ThucUong::get_origin() const
{
    return _origin;
}

void ThucUong::print(std::ostream &os) const
{
    os << _name << ", ";
    os << _inf << ", ";
    os << _id_sp << ", ";
    os << _type << ", ";
    os << _quantity << ", ";
    os << _money << ", ";
    os << _discount << ", ";
    os << _manufacture_Date << ", ";
    os << _expiry_Date;
}

std::ostream &operator<<(std::ostream &os, const ThucUong &thucUong)
{

    return os;
}