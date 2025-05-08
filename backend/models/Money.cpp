#include "Money.h"
std::vector<std::string> Money::type = {"VND", "USD"};
float Money::exchange_rate = 25.0f;

Money::Money()
{
    _value = "0";
    _type = "VND";
}

Money::~Money() = default;

Money::Money(const std::string &money)
{
    _value = money;
    _type = "VND";
}

Money::Money(const std::string &money, const std::string &type)
{
    _value = money;
    _type = type;
}

std::string Money::get_value() const
{
    return _value;
}

void Money::set_value(const std::string &money)
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

void Money::operator=(const Money &money)
{
    _value = money.get_value();
    _type = money._type;
}

Money operator+(const Money &money1, const Money &money2)
{
    if (money1._type == money2._type)
    {
        return Money(std::to_string(std::stoll(money1.get_value()) + std::stoll(money2.get_value())), money1._type);
    }
    else
    {
        long long value = money1.ConvertToVND() + money2.ConvertToVND();
        return Money(std::to_string(value), "VND");
    }
}

Money operator-(const Money &money1, const Money &money2)
{
    if (money1._type == money2._type)
    {
        return Money(std::to_string(std::stoll(money1.get_value()) - std::stoll(money2.get_value())), money1._type);
    }
    else
    {
        long long value = money1.ConvertToVND() - money2.ConvertToVND();
        return Money(std::to_string(value), "VND");
    }
}

Money operator*(const int &value, const Money &money)
{
    return Money(std::to_string(value * std::stoll(money.get_value())), money._type);
}

Money operator*(const Money &money, const float &value)
{
    return Money(std::to_string(static_cast<long long>(std::stoll(money.get_value()) * value)), money._type);
}

bool operator==(const Money &money1, const Money &money2)
{
    return (money1.get_value() == money2.get_value() && money1._type == money2._type);
}

bool operator<(const Money &money1, const Money &money2)
{
    if (money1._type == money2._type)
    {
        return std::stoll(money1.get_value()) < std::stoll(money2.get_value());
    }
    else
    {
        return money1.ConvertToVND() < money2.ConvertToVND();
    }
}

bool operator>(const Money &money1, const Money &money2)
{
    if (money1._type == money2._type)
    {
        return std::stoll(money1.get_value()) > std::stoll(money2.get_value());
    }
    else
    {
        return money1.ConvertToVND() > money2.ConvertToVND();
    }
}

std::ostream &operator<<(std::ostream &os, const Money &money)
{
    os << money.get_value() << " " << money._type;
    return os;
}