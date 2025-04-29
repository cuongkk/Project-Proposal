#ifndef CART_H
#define CART_H

#include "KhoHang.h"
#include "LinkedList.h"
class Cart
{

public:
    Cart();
    ~Cart();
    LinkedList _sanpham;

    int get_size() const;
    float get_cost() const;

    bool add(KhoHang &, std::unique_ptr<SanPham>);
    void remove(KhoHang &, std::unique_ptr<SanPham>);

    void operator=(const Cart &);
    friend std::ostream &operator<<(std::ostream &os, const Cart &);
};
#endif