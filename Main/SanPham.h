#ifndef SANPHAM_H
#define SANPHAM_H

#include "Utils.h"
#include <iostream>
#include <string>
#include <memory>
#include <vector>

class SanPham
{
protected:
    std::string _id;
    std::string _type; // Thức ăn, thức uống
    int _quantity;
    float _cost;
    float _discount;
    std::string _manufacture_Date;
    std::string _expiry_Date;
    static std::vector<int> _id_counter;
    SanPham *_origin = nullptr;

public:
    SanPham();
    virtual ~SanPham() = default;
    SanPham(const std::string &, const int &, const float &, const float &,
            const std::string &, const std::string &);

    virtual std::unique_ptr<SanPham> clone() const = 0;
    virtual SanPham *get_origin() const = 0;

    void set_counter(const int &);
    void set_id();
    std::string get_id() const;
    void set_quantity(int quantity);
    int get_quantity() const;
    void set_cost(int cost);
    float get_cost() const;
    void set_discount(int discount);
    float get_discount() const;

    friend float operator+(const float &, const SanPham &);
    friend std::unique_ptr<SanPham> operator+(std::unique_ptr<SanPham>, const SanPham &);
    friend std::unique_ptr<SanPham> operator+(const SanPham &, const SanPham &);

    friend std::unique_ptr<SanPham> operator-(std::unique_ptr<SanPham>, const SanPham &ss);
    friend std::unique_ptr<SanPham> operator-(const SanPham &, const SanPham &);

    friend bool operator==(const SanPham &, const SanPham &);
    virtual void print(std::ostream &) const = 0;
    friend std::ostream &operator<<(std::ostream &, const SanPham &sp);
};

#endif