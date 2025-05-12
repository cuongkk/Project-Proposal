
#ifndef CART_H
#define CART_H

#include "Main.h"
#include "Product.h"
#include "LinkedList.h"
class Cart
{
protected:
    std::string _id_Customer;
    LinkedList<Product> _list;

public:
    Cart();
    ~Cart();
    Cart(const std::string &, const LinkedList<Product> &);

    std::unique_ptr<Cart> clone() const;

    int get_size() const;
    std::string get_money() const;
    LinkedList<Product> get_list() const;

    bool add(std::unique_ptr<Product>);
    void remove(std::unique_ptr<Product>);

    void operator=(const Cart &);
    friend std::ostream &operator<<(std::ostream &os, const Cart &);
};
#endif