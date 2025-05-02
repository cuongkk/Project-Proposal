#ifndef THUCAN_H
#define THUCAN_H

#include "Main.h"
#include "SanPham.h"

class ThucAn : public SanPham
{
private:
    std::string _name;
    std::string _inf;

public:
    ThucAn();
    ~ThucAn();
    ThucAn(const std::string &, const std::string &,
           const std::string &, const int &, const std::string &,
           const std::string &, const float &,
           const std::string &, const std::string &);

    std::unique_ptr<SanPham> clone() const override;
    SanPham *get_origin() const override;

    void print(std::ostream &) const override;

    friend std::ostream &operator<<(std::ostream &, const ThucAn &);
};
#endif