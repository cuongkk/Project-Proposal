#ifndef THUCUONG_H
#define THUCUONG_H
#include "SanPham.h"
#include <iostream>
#include <string>
class ThucUong : public SanPham
{
private:
    std::string _name;
    std::string _inf;

public:
    ThucUong();
    ~ThucUong();
    ThucUong(const std::string &, const std::string &,
             const int &, const std::string &, const int &, const int &, const int &,
             const std::string &, const std::string &);
    void print(std::ostream &) const override;

    friend std::ostream &operator<<(std::ostream &os, const ThucUong &ThucUong);
};
#endif