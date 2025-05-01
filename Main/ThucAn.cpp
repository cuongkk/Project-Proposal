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
               const std::string &type, const int &quantity, const float &cost, const float &discount,
               const std::string &manufacture_Date, const std::string &expiry_Date)
    : SanPham(type, quantity, cost, discount, manufacture_Date, expiry_Date)
{
    _name = name;
    _inf = inf;
}

bool ThucAn::containsKeyword(const std::string &keyword, const int& option) const 
{
    std::regex pattern(keyword, std::regex_constants::icase);// không phân biệt hoa thường
    switch (option)
    {
        case 1: // search by name, information
            return std::regex_search(_name, pattern) || std::regex_search(_inf, pattern) || std::regex_search(_id, pattern);; 
        case 2: // search by type
            return std::regex_search(_type, pattern);
        case 3: // sort by lower cost 
            return (_cost <= std::stof(keyword));
        case 4: // sort by higher cost
            return (_cost >= std::stof(keyword));
        default:
            return false; // Invalid option
    }
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

void ThucAn::print(std::ostream &os) const
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

std::ostream &operator<<(std::ostream &os, const ThucAn &thucAn)
{
    return os;
}