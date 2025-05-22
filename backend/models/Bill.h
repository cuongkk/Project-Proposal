
#ifndef BILL_H
#define BILL_H

#include "Main.h"
#include "Cart.h"
#include "UserManagement.h"
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
    Bill();
    ~Bill();
    Bill(const Bill &);
    Bill(Bill &&) noexcept;
    Bill(const std::string &, Cart &&, const DateTime &);

    std::shared_ptr<Bill> clone();
    Bill *get_origin();

    std::string get_id() const;
    std::string get_id_Customer() const;

    std::unique_ptr<Bill> confirmBill(UserManagement &, std::string &, const DateTime &);
    Cart get_cart() const;
    std::string get_totalCost() const;
    DateTime get_dateTime() const;

    friend std::ostream &operator<<(std::ostream &, const Bill &);
};
#endif