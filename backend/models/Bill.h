
#ifndef BILL_H
#define BILL_H

#include "Main.h"
#include "Cart.h"
#include "Customer.h"
#include "DateTime.h"

class Bill
{
protected:
    std::string _id_Bill;
    std::string _id_Customer;
    Cart _cart;
    std::string _totalCost;
    DateTime _dateTime;
    Bill *_origin = nullptr;

public:
    static std::vector<int> _id_counter_bill;
    Bill();
    ~Bill();
    Bill(const Bill &);
    Bill(Bill &&) noexcept;
    Bill(const std::string &, const std::string &, Cart &&, const DateTime &);

    std::shared_ptr<Bill> clone();
    Bill *get_origin();

    std::string get_id() const;
    std::string get_id_Customer() const;

    std::shared_ptr<Bill> confirmBill(const std::string &, User *, const DateTime &);
    Cart get_cart() const;
    std::string get_totalCost() const;
    DateTime get_dateTime() const;

    friend std::ostream &operator<<(std::ostream &, const Bill &);
};
#endif