#include "Product.h"
Product::Product()
{
    _id_sp = "";
    _quantity = 0;
    Money _money;
    _discount = 0;
    _manufacture_Date = DateTime();
    _expiry_Date = DateTime();
    _origin = this;
}

Product::Product(const int &quantity, const std::string &money,
                 const float &discount,
                 const DateTime &manufacture_Date, const DateTime &expiry_Date)
{
    _id_sp = set_id("SP", _id_counter_sp);
    _quantity = quantity;
    _money = Money(money);
    _discount = discount;
    _manufacture_Date = manufacture_Date;
    _expiry_Date = expiry_Date;
    _origin = this;
}

void Product::set_counter(const int &index)
{
    _id_counter_sp[index] = 0;
}

std::string Product::get_id() const
{
    return _id_sp;
}

void Product::set_quantity(const int &quantity)
{
    _quantity = quantity;
}

int Product::get_quantity() const
{
    return _quantity;
}

void Product::set_money(const std::string &money, const std::string &type_money)
{
    _money.set_value(money);
    _money.set_type(type_money);
}

std::string Product::get_money() const
{
    return _money.get_money();
}

void Product::set_discount(const int &discount)
{
    _discount = discount;
}

float Product::get_discount() const
{
    return _discount;
}

DateTime Product::get_manufacture_Date() const
{
    return _manufacture_Date;
}

DateTime Product::get_expiry_Date() const
{
    return _expiry_Date;
}

std::string operator+(const long long &m1, const std::string &m2)
{
    long long value = m1 + std::stoll(m2);
    return std::to_string(value);
}

std::string operator+(const std::string &a, const Product &b)
{
    long long money_value = std::stoll(b._money.get_value());

    long long total_cost = money_value * b.get_quantity() * (100 - b.get_discount()) / 100;
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

bool operator==(const Product &a, const Product &b)
{
    return a.get_id() == b.get_id();
}
std::ostream &operator<<(std::ostream &os, const Product &sp)
{
    sp.print(os);
    return os;
}