#pragma once
#ifndef DRINK_H
#define DRINK_H

#include "Main.h"
#include "Product.h"

class Drink : public Product
{
private:
    std::string _name;
    std::string _inf;

public:
    Drink();
    ~Drink();
    Drink(const std::string &,
          const std::string &,
          const int &,
          const std::string &,
          const float &,
          const DateTime &,
          const DateTime &);

    std::unique_ptr<Product> clone() const override;
    Product *get_origin() override;
    std::string get_name() const override;
    std::string get_inf() const override;

    void print(std::ostream &) const override;
    friend std::ostream &operator<<(std::ostream &os, const Drink &Drink);
};
#endif