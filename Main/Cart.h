#ifndef CART_H
#define CART_H

#include "LinkedList.h"
class Cart
{

public:
    Cart();
    ~Cart();
    LinkedList _sanpham;

    int get_size() const;
    float get_cost() const;

    void add(std::unique_ptr<SanPham>);
    void remove(const int &);

    void operator=(const Cart &);
    friend std::ostream &operator<<(std::ostream &os, const Cart &);
};
#endif