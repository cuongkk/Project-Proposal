#ifndef PRODUCT_H
#define PRODUCT_H

#include "Main.h"
#include "Money.h"
#include "DateTime.h"

class Product
{
protected:
    std::string _id_sp;
    int _quantity;
    float _discount;
    Money _money;
    DateTime _manufacture_Date;
    DateTime _expiry_Date;
    Product *_origin = nullptr;

public:
    static std::vector<int> _id_counter_sp;
    Product();
    Product(const Product &);
    Product(Product &&) noexcept;
    virtual ~Product() = default;
    Product(const int &, const std::string &,
            const float &, const DateTime &, const DateTime &);

    virtual std::unique_ptr<Product> clone() const = 0;
    virtual Product *get_origin() = 0;

    virtual std::string get_name() const = 0;
    virtual std::string get_inf() const = 0;

    void set_counter(const int &);
    std::string get_id() const;
    void set_quantity(const int &);
    int get_quantity() const;
    void set_money(const std::string &, const std::string &);
    std::string get_money() const;
    void set_discount(const int &);
    float get_discount() const;
    DateTime get_manufacture_Date() const;
    DateTime get_expiry_Date() const;

    friend std::string operator+(const std::string &, const std::string &);
    friend std::string operator+(const std::string &, const Product &);

    friend bool operator==(const Product &, const Product &);
    virtual void print(std::ostream &) const = 0;
    friend std::ostream &operator<<(std::ostream &, const Product &sp);
};

#endif