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
                   const int &id, const std::string &type, const int &quantity, const int &cost, const int &discount,
                   const std::string &manufacture_Date, const std::string &expiry_Date)
    : SanPham(id, type, quantity, cost, discount, manufacture_Date, expiry_Date)
{
    _name = name;
    _inf = inf;
}

void ThucUong::print(std::ostream &os) const
{
    os << _name << ", ";
    os << _inf << ", ";
    os << _id << ", ";
    os << _type << ", ";
    os << _quantity << ", ";
    os << _cost << ", ";
    os << _discount << ", ";
    os << _manufacture_Date << ", ";
    os << _expiry_Date << ", ";
}

std::ostream &operator<<(std::ostream &os, const ThucUong &thucUong)
{

    return os;
}