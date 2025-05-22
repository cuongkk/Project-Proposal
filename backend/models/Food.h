#ifndef FOOD_H
#define FOOD_H

#include "Main.h"
#include "Product.h"

class Food : public Product
{
private:
    std::string _name;
    std::string _inf;

public:
    Food();
    ~Food();
    Food(
        const std::string &,
        const std::string &,
        const std::string &,
        const int &,
        const std::string &,
        const std::string &,
        const DateTime &,
        const DateTime &,
        const std::string &);

    std::unique_ptr<Product> clone() const override;
    Product *get_origin() override;
    std::string get_name() const override;
    std::string get_inf() const override;

    void print(std::ostream &) const override;

    friend std::ostream &operator<<(std::ostream &, const Food &);
};
#endif