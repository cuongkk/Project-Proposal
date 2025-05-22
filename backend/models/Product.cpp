#include "Product.h"
Product::Product()
{
    _id_sp = "";
    _quantity = 0;
    Money _money;
    _discount = "";
    _manufacture_Date = DateTime();
    _expiry_Date = DateTime();
    _origin = this;
}

Product::Product(const Product &sp)
{
    _id_sp = sp.get_id();
    _quantity = sp.get_quantity();
    _money = sp._money;
    _discount = sp.get_discount();
    _manufacture_Date = sp.get_manufacture_Date();
    _expiry_Date = sp.get_expiry_Date();
    _imagePath = sp.get_imagePath();
    _origin = this;
}

Product::Product(Product &&sp) noexcept
{
    _id_sp = std::move(sp._id_sp);
    _quantity = std::move(sp._quantity);
    _money = std::move(sp._money);
    _discount = std::move(sp._discount);
    _manufacture_Date = std::move(sp._manufacture_Date);
    _expiry_Date = std::move(sp._expiry_Date);
    _imagePath = std::move(sp._imagePath);
    _origin = this;
}

Product::Product(const std::string &id_sp, const int &quantity, const std::string &money,
                 const std::string &discount,
                 const DateTime &manufacture_Date, const DateTime &expiry_Date, const std::string &imagePath)
{
    _id_sp = id_sp;
    _quantity = quantity;
    _money = Money(money);
    _discount = discount;
    _manufacture_Date = manufacture_Date;
    _expiry_Date = expiry_Date;
    _imagePath = imagePath;
    _origin = this;
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

std::string Product::get_discount() const
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

void Product::set_imagePath(const std::string &imagePath)
{
    _imagePath = imagePath;
}

std::string Product::get_imagePath() const
{
    return _imagePath;
}

std::string operator+(const long long &m1, const std::string &m2)
{
    long long value = m1 + std::stoll(m2);
    return std::to_string(value);
}

std::string operator+(const std::string &a, const Product &b)
{
    long long money_value = std::stoll(b._money.get_value());

    long long total_cost = money_value * b.get_quantity() * (100 - std::stof(b.get_discount()));
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