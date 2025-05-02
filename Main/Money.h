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
    Money(const std::string &, const std::string &);
    static std::vector<std::string> type;

    std::string get_money() const;
    void set_money(const std::string &);
    void set_type(const std::string &);

    long long ConvertToVND() const;

    friend std::ostream &operator<<(std::ostream &, const Money &);
};
#endif