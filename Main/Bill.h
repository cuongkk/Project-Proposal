#ifndef BILL_H
#define BILL_H

#include "SanPham.h"
#include "Customer.h"

#include <iostream>
#include <string>
class Bill : public SanPham, public Customer
{
protected:
    int _id;
    int *_id_SanPham;
    int _id_Customer;
    int _cost;

public:
    Bill();
    ~Bill();
};
#endif