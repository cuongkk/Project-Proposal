#ifndef BILL_H
#define BILL_H

#include "KhoHang.h"
#include "Customer.h"
#include "Cart.h"

#include <iostream>
#include <string>
class Bill
{
protected:
    int _id;
    int _id_Customer;
    Cart _cart;
    int _totalCost;

public:
    Bill();
    ~Bill();
    void confirmBill(KhoHang &khoHang, Cart &&);

    friend std::ostream &operator<<(std::ostream &, const Bill &);
};
#endif