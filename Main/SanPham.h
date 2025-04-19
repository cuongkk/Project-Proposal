#ifndef SANPHAM_H
#define SANPHAM_H

#include <string>
class SanPham
{
private:
    int _id;
    std::string _name;
    int _quantity;

public:
    SanPham();
    SanPham(const int &, const std::string &, const int &);
};

#endif