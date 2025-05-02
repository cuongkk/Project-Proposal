#ifndef SANPHAM_H
#define SANPHAM_H

#include "Main.h"
#include "Money.h"

class SanPham
{
protected:
    std::string _id_sp;
    std::string _type; // Thức ăn, thức uống
    int _quantity;
    float _discount;
    std::string _manufacture_Date;
    std::string _expiry_Date;
    static std::vector<int> _id_counter_sp;
    SanPham *_origin = nullptr;

public:
    Money _money;
    SanPham();
    virtual ~SanPham() = default;
    SanPham(const std::string &, const int &, const std::string &, const std::string &,
            const float &,
            const std::string &, const std::string &);

    virtual std::unique_ptr<SanPham> clone() const = 0;
    virtual SanPham *get_origin() const = 0;

    virtual std::string get_name() const = 0;
    void set_counter(const int &);
    std::string get_id() const;
    void set_quantity(const int &);
    int get_quantity() const;
    void set_money(const std::string &, const std::string &);
    std::pair<std::string, std::string> get_money() const;
    void set_discount(const int &);
    float get_discount() const;

    friend std::string operator+(const std::string &, const std::string &);
    friend std::string operator+(const std::string &, const SanPham &);

    friend std::string operator*(const int &, const std::string &);
    friend std::string operator*(const std::string &, const float &);

    friend bool operator==(const SanPham &, const SanPham &);
    virtual void print(std::ostream &) const = 0;
    friend std::ostream &operator<<(std::ostream &, const SanPham &sp);
};

#endif