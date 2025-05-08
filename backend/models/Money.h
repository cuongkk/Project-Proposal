#ifndef MONEY_H
#define MONEY_H

#include "Main.h"
class Money
{
protected:
    std::string _value;

public:
    static float exchange_rate;
    std::string _type;

    Money();
    ~Money();
    Money(const std::string &);
    Money(const std::string &, const std::string &);
    static std::vector<std::string> type;

    void set_value(const std::string &);
    std::string get_value() const;
    void set_type(const std::string &);

    long long ConvertToVND() const;

    void operator=(const Money &);
    friend Money operator+(const Money &, const Money &);
    friend Money operator-(const Money &, const Money &);
    friend Money operator*(const int &, const Money &);
    friend Money operator*(const Money &, const float &);
    friend bool operator==(const Money &, const Money &);
    friend bool operator<(const Money &, const Money &);
    friend bool operator>(const Money &, const Money &);
    friend std::ostream &operator<<(std::ostream &, const Money &);
};
#endif