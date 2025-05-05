#include "ThucAn.h"

ThucAn::ThucAn() : SanPham()
{
    _name = "";
    _inf = "";
}

ThucAn::~ThucAn()
{
}

ThucAn::ThucAn(const std::string &name, const std::string &inf,
               const std::string &type, const int &quantity, const std::string &money,
               const std::string &type_money, const float &discount,
               const std::string &manufacture_Date, const std::string &expiry_Date)
    : SanPham(type, quantity, money, type_money, discount, manufacture_Date, expiry_Date)
{
    _name = name;
    _inf = inf;
}

std::unique_ptr<SanPham> ThucAn::clone() const
{
    auto cloned = std::make_unique<ThucAn>(*this);
    auto nonconst_this = const_cast<ThucAn *>(this);
    cloned->_origin = static_cast<SanPham *>(nonconst_this);
    return cloned;
}

SanPham *ThucAn::get_origin() const
{
    return _origin;
}

std::string ThucAn::get_name() const
{
    return _name;
}

std::string ThucAn::get_inf() const
{
    return _inf;
}

void ThucAn::print(std::ostream &os) const
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

std::ostream &operator<<(std::ostream &os, const ThucAn &thucAn)
{
    return os;
}