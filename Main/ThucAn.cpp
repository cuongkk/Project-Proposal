#include "ThucAn.h"

ThucAn::ThucAn() : SanPham()
{
    _name = "";
    _inf = "";
}

ThucAn::ThucAn(const std::string &name, const std::string &inf,
               const int &id, const std::string &type, const int &quantity, const int &cost, const int &discount,
               const std::string &manufacture_Date, const std::string &expiry_Date)
    : SanPham(id, type, quantity, cost, discount, manufacture_Date, expiry_Date)
{
    _name = name;
    _inf = inf;
}
