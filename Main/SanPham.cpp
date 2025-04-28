#include "SanPham.h"
#include "ThucAn.h"
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

SanPham::SanPham(const int &id, const std::string &type, const int &quantity, const float &cost, const float &discount,
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

int SanPham::get_id() const
{
    return _id;
}
void SanPham::set_quantity(int quantity)
{
    _quantity = quantity;
}

int SanPham::get_quantity() const
{
    return _quantity;
}

void SanPham::set_cost(int cost)
{
    _cost = cost;
}

float SanPham::get_cost() const
{
    return _cost;
}

void SanPham::set_discount(int discount)
{
    _discount = discount;
}

float SanPham::get_discount() const
{
    return _discount;
}

float operator+(const float &a, std::unique_ptr<SanPham> b)
{
    auto res = std::make_unique<ThucAn>();
    res->set_cost(a + b->get_cost() * (1 - b->get_discount()));
    return res->get_cost();
}
std::unique_ptr<SanPham> operator+(const SanPham &a, const SanPham &b)
{
    auto res = std::make_unique<ThucAn>();
    res->set_cost(a.get_cost() * (1 - a.get_discount()) + b.get_cost() * (1 - b.get_discount()));
    return res;
}

std::unique_ptr<SanPham> operator+(std::unique_ptr<SanPham> a, const SanPham &b)
{
    auto res = std::make_unique<ThucAn>();
    res->set_cost(a->get_cost() * (1 - a->get_discount()) + b.get_cost() * (1 - b.get_discount()));
    return res;
}

std::unique_ptr<SanPham> operator-(const SanPham &a, const SanPham &b)
{
    auto res = std::make_unique<ThucAn>();
    res->set_cost(a.get_cost() * (1 - a.get_discount()) + b.get_cost() * (1 - b.get_discount()));
    return res;
}

std::unique_ptr<SanPham> operator-(std::unique_ptr<SanPham> a, const SanPham &b)
{
    auto res = std::make_unique<ThucAn>();
    res->set_cost(a->get_cost() * (1 - a->get_discount()) + b.get_cost() * (1 - b.get_discount()));
    return res;
}

std::ostream &operator<<(std::ostream &os, const SanPham &value)
{
    value.print(os);
    return os;
}