#include "SanPham.h"
#include "ThucAn.h"
SanPham::SanPham()
{
    _id_sp = "";
    _type = "";
    _quantity = 0;
    Money _money;
    _discount = 0;
    _manufacture_Date = "";
    _expiry_Date = "";
}

SanPham::SanPham(const std::string &type, const int &quantity, const std::string &money,
                 const std::string &type_money, const float &discount,
                 const std::string &manufacture_Date, const std::string &expiry_Date)
{
    _id_sp = set_id("SP", _id_counter_sp);
    _type = type;
    _quantity = quantity;
    _money = Money(money, type_money);
    _discount = discount;
    _manufacture_Date = manufacture_Date;
    _expiry_Date = expiry_Date;
}

void SanPham::set_counter(const int &index)
{
    _id_counter_sp[index] = 0;
}

std::string SanPham::get_id() const
{
    return _id_sp;
}

std::string SanPham::get_type() const
{
    return _type;
}

void SanPham::set_quantity(const int &quantity)
{
    _quantity = quantity;
}

int SanPham::get_quantity() const
{
    return _quantity;
}

void SanPham::set_money(const std::string &money, const std::string &type_money)
{
    _money.set_money(money);
    _money.set_type(type_money);
}

std::pair<std::string, std::string> SanPham::get_money() const
{
    return std::make_pair(_money.get_money(), _money._type);
}

void SanPham::set_discount(const int &discount)
{
    _discount = discount;
}

float SanPham::get_discount() const
{
    return _discount;
}

std::string SanPham::get_manufacture_Date() const
{
    return _manufacture_Date;
}

std::string SanPham::get_expiry_Date() const
{
    return _expiry_Date;
}

std::string operator+(const long long &m1, const std::string &m2)
{
    long long value = m1 + std::stoll(m2);
    return std::to_string(value);
}

std::string operator+(const std::string &a, const SanPham &b)
{
    long long money_value = std::stoll(b._money.get_money());

    long long total_cost = money_value * b.get_quantity() * (1 - b.get_discount());
    if (a == "")
    {
        return std::to_string(total_cost);
    }
    else
    {
        std::string total = std::stoll(a) + std::to_string(total_cost);
        return total;
    }
}

bool operator==(const SanPham &a, const SanPham &b)
{
    return a.get_id() == b.get_id();
}
std::ostream &operator<<(std::ostream &os, const SanPham &sp)
{
    sp.print(os);
    return os;
}