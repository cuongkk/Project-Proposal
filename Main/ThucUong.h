#ifndef THUCUONG_H
#define THUCUONG_H

#include "Main.h"
#include "SanPham.h"

class ThucUong : public SanPham
{
private:
    std::string _name;
    std::string _inf;

public:
    ThucUong();
    ~ThucUong();
    ThucUong(const std::string &, const std::string &,
             const std::string &, const int &, const std::string &,
             const std::string &, const float &,
             const std::string &, const std::string &);

    std::unique_ptr<SanPham> clone() const override;
    SanPham *get_origin() const override;
    std::string get_name() const override;

    void print(std::ostream &) const override;
    friend std::ostream &operator<<(std::ostream &os, const ThucUong &ThucUong);
};
#endif