#include "DateTime.h"

DateTime::DateTime()
{
    _day = 0;
    _month = 0;
    _year = 0;
    _hour = 0;
    _minute = 0;
    _second = 0;
}
DateTime::~DateTime() = default;

DateTime::DateTime(int day, int month, int year)
{
    _day = day;
    _month = month;
    _year = year;
    _hour = 0;
    _minute = 0;
    _second = 0;
}

void DateTime::set_day(int day)
{
    _day = day;
}

int DateTime::get_day() const
{
    return _day;
}

void DateTime::set_month(int month)
{
    _month = month;
}

int DateTime::get_month() const
{
    return _month;
}

void DateTime::set_year(int year)
{
    _year = year;
}

int DateTime::get_year() const
{
    return _year;
}

void DateTime::operator=(const DateTime &dt)
{
    _day = dt.get_day();
    _month = dt.get_month();
    _year = dt.get_year();
}
bool operator==(const DateTime &dt1, const DateTime &dt2)
{
    return (dt1._day == dt2._day && dt1._month == dt2._month && dt1._year == dt2._year);
}

bool operator<(const DateTime &dt1, const DateTime &dt2)
{
    if (dt1._year != dt2._year)
        return dt1._year < dt2._year;
    if (dt1._month != dt2._month)
        return dt1._month < dt2._month;
    return dt1._day < dt2._day;
}

bool operator>(const DateTime &dt1, const DateTime &dt2)
{
    if (dt1._year != dt2._year)
        return dt1._year > dt2._year;
    if (dt1._month != dt2._month)
        return dt1._month > dt2._month;
    return dt1._day > dt2._day;
}

std::ostream &operator<<(std::ostream &os, const DateTime &dt)
{
    os << dt._day << "/" << dt._month << "/" << dt._year;
    return os;
}