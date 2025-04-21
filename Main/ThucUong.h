#ifndef THUCUONG_H
#define THUCUONG_H
#include "SanPham.h"
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
};
#endif