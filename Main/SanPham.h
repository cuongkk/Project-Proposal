#ifndef SANPHAM_H
#define SANPHAM_H

#include <string>
class SanPham
{
protected:
    int _id;
    std::string _type; // Thức ăn, thức uống
    int _quantity;
    int _cost;
    int _discount;
    std::string _manufacture_Date;
    std::string _expiry_Date;

public:
    SanPham();
    ~SanPham();
    SanPham(const int &, const std::string &, const int &, const int &, const int &,
            const std::string &, const std::string &);
};

#endif