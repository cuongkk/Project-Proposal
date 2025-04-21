#ifndef THUCAN_H
#define THUCAN_H
#include "SanPham.h"
#include <string>
class ThucAn : public SanPham
{
private:
    std::string _name;
    std::string _inf;

public:
    ThucAn();
    ~ThucAn();
    ThucAn(const std::string &, const std::string &,
           const int &, const std::string &, const int &, const int &, const int &,
           const std::string &, const std::string &);
};
#endif