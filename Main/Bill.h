#ifndef BILL_H
#define BILL_H

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
    float _totalCost;

public:
    Bill();
    ~Bill();
    void confirmBill(Cart &&);
    float get_totalCost() const;

    friend std::ostream &operator<<(std::ostream &, const Bill &);
};
#endif