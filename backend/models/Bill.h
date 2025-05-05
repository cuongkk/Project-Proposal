#ifndef BILL_H
#define BILL_H

#include "Main.h"
#include "Cart.h"
#include "UserManagement.h"

class Bill
{
protected:
    std::string _id_Bill;
    std::string _id_Customer;
    Cart _cart;
    std::string _totalCost;
    Bill *_origin = nullptr;

public:
    static std::vector<int> _id_counter_bill;

    Bill();
    ~Bill();
    Bill(const std::string &, Cart &&);

    std::unique_ptr<Bill> clone();
    Bill *get_origin();

    void set_counter(const int &);
    std::string get_id() const;
    std::string get_id_Customer() const;

    std::unique_ptr<Bill> confirmBill(UserManagement &, const std::string &, Cart &&);
    std::string get_totalCost() const;

    friend std::ostream &operator<<(std::ostream &, const Bill &);
};
#endif