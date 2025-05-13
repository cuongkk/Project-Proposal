#ifndef DATETIME_H
#define DATETIME_H

#include "Main.h"
class DateTime
{
private:
    std::string _date;
    int _day;
    int _month;
    int _year;
    int _hour;
    int _minute;
    int _second;

public:
    DateTime();
    ~DateTime();
    DateTime(const DateTime &);
    DateTime(int day, int month, int year);

    void set_day(int day);
    int get_day() const;
    void set_month(int month);
    int get_month() const;
    void set_year(int year);
    int get_year() const;

    std::string get_date() const;

    void operator=(const DateTime &);
    friend bool operator==(const DateTime &, const DateTime &);
    friend bool operator<(const DateTime &, const DateTime &);
    friend bool operator>(const DateTime &, const DateTime &);
    friend std::ostream &operator<<(std::ostream &, const DateTime &);
};

#endif