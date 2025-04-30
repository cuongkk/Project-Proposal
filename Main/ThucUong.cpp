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
                   const std::string &type, const int &quantity, const float &cost, const float &discount,
                   const std::string &manufacture_Date, const std::string &expiry_Date)
    : SanPham(type, quantity, cost, discount, manufacture_Date, expiry_Date)
{
    _name = name;
    _inf = inf;
}


bool ThucUong::containsKeyword(const std::string& keyword) const
{
    std::regex pattern(keyword, std::regex_constants::icase);
    return std::regex_search(_name, pattern) || std::regex_search(_inf, pattern);
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
    os << _id << ", ";
    os << _type << ", ";
    os << _quantity << ", ";
    os << _cost << ", ";
    os << _discount << ", ";
    os << _manufacture_Date << ", ";
    os << _expiry_Date;
}

std::ostream &operator<<(std::ostream &os, const ThucUong &thucUong)
{

    return os;
}