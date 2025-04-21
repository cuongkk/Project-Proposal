#include "SanPham.h"

SanPham::SanPham()
{
    _id = 0;
    _type = "";
    _quantity = 0;
    _cost = 0;
    _discount = 0;
    _manufacture_Date = "";
    _expiry_Date = "";
}

SanPham::~SanPham()
{
}

SanPham::SanPham(const int &id, const std::string &type, const int &quantity, const int &cost, const int &discount,
                 const std::string &manufacture_Date, const std::string &expiry_Date)
{
    _id = id;
    _type = type;
    _quantity = quantity;
    _cost = cost;
    _discount = discount;
    _manufacture_Date = manufacture_Date;
    _expiry_Date = expiry_Date;
}
