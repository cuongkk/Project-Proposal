#include "Money.h"
std::vector<std::string> Money::type = {"VND", "USD"};
float Money::exchange_rate = 25.0f;

Money::Money()
{
    _value = "0";
    _type = "VND";
}

Money::~Money() = default;

Money::Money(const std::string &money, const std::string &type)
{
    _value = money;
    _type = type;
}

std::string Money::get_money() const
{
    return _value;
}

void Money::set_money(const std::string &money)
{
    _value = money;
}

void Money::set_type(const std::string &type)
{
    _type = type;
}

long long Money::ConvertToVND() const
{
    long long value = std::stoll(_value);
    if (_type == "USD")
    {
        return value * static_cast<long long>(exchange_rate);
    }
    return value;
}

std::ostream &operator<<(std::ostream &os, const Money &money)
{
    os << money.get_money() << " " << money._type;
    return os;
}