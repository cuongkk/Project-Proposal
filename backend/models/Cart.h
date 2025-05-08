
#ifndef CART_H
#define CART_H

#include "Main.h"
#include "KhoHang.h"
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
    Cart(const std::string &);

    std::unique_ptr<Cart> clone() const;

    int get_size() const;
    std::string get_money() const;

    bool add(KhoHang &, std::unique_ptr<Product>);
    void remove(KhoHang &, std::unique_ptr<Product>);

    void operator=(const Cart &);
    friend std::ostream &operator<<(std::ostream &os, const Cart &);
};
#endif