#ifndef SANPHAM_H
#define SANPHAM_H

#include <iostream>
#include <string>
#include <memory>
class SanPham
{
protected:
    int _id;
    std::string _type; // Thức ăn, thức uống
    int _quantity;
    float _cost;
    float _discount;
    std::string _manufacture_Date;
    std::string _expiry_Date;
    SanPham *_origin = nullptr;

public:
    SanPham();
    virtual ~SanPham() = default;
    SanPham(const int &, const std::string &, const int &, const float &, const float &,
            const std::string &, const std::string &);

    virtual std::unique_ptr<SanPham> clone() const = 0;
    virtual SanPham *get_origin() const = 0;

    int get_id() const;
    void set_quantity(int quantity);
    int get_quantity() const;
    void set_cost(int cost);
    float get_cost() const;
    void set_discount(int discount);
    float get_discount() const;

    friend float operator+(const float &a, std::unique_ptr<SanPham> b);
    friend std::unique_ptr<SanPham> operator+(std::unique_ptr<SanPham> a, const SanPham &b);
    friend std::unique_ptr<SanPham> operator+(const SanPham &a, const SanPham &b);

    friend std::unique_ptr<SanPham> operator-(std::unique_ptr<SanPham> a, const SanPham &b);
    friend std::unique_ptr<SanPham> operator-(const SanPham &a, const SanPham &b);

    virtual void print(std::ostream &) const = 0;
    friend std::ostream &operator<<(std::ostream &, const SanPham &sp);
};

#endif