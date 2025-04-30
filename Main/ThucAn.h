#ifndef THUCAN_H
#define THUCAN_H
#include "SanPham.h"
#include <iostream>
#include <string>
class ThucAn : public SanPham
{
private:
    std::string _name;
    std::string _inf;

public:
    ThucAn();
    ~ThucAn();
    ThucAn(const std::string &, const std::string &,
           const std::string &, const int &, const float &, const float &,
           const std::string &, const std::string &);

    std::unique_ptr<SanPham> clone() const override;
    SanPham *get_origin() const override;

    void print(std::ostream &) const override;

    friend std::ostream &operator<<(std::ostream &os, const ThucAn &thucAn);
};
#endif