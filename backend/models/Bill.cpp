#include "Bill.h"

Bill::Bill()
{
    _id_Bill = "";
    _id_Customer = "";
    _totalCost = 0.0f;
}

Bill::~Bill() = default;

Bill::Bill(const Bill &other)
    : _id_Bill(other._id_Bill),
      _id_Customer(other._id_Customer),
      _cart(other._cart),
      _totalCost(other._totalCost),
      _dateTime(other._dateTime)
{
}

Bill::Bill(Bill &&other) noexcept
{
    _id_Bill = std::move(other._id_Bill);
    _id_Customer = std::move(other._id_Customer);
    _cart = std::move(other._cart);
    _totalCost = std::move(other._totalCost);
    _dateTime = std::move(other._dateTime);
}

Bill::Bill(const std::string &id_Bill, const std::string &id_Customer, Cart &&cart, const DateTime &dateTime)
    : _dateTime(dateTime)
{
    _id_Bill = id_Bill;
    _id_Customer = id_Customer;
    _cart = std::move(cart);
    _totalCost = _cart.get_money();
}

std::shared_ptr<Bill> Bill::clone()
{
    return std::make_shared<Bill>(*this);
}

Bill *Bill::get_origin()
{
    return _origin;
}

std::string Bill::get_id() const
{
    return _id_Bill;
}

std::string Bill::get_id_Customer() const
{
    return _id_Customer;
}

std::shared_ptr<Bill> Bill::confirmBill(const std::string &id_bill, User *customer, const DateTime &dateTime)
{
    auto cart = customer->get_cart();
    customer->get_origin()->_cart.clear();
    auto bill = std::make_shared<Bill>(id_bill, customer->get_id(), std::move(cart), dateTime);
    return bill;
}

Cart Bill::get_cart() const
{
    return _cart;
}

std::string Bill::get_totalCost() const
{
    return _totalCost;
}

DateTime Bill::get_dateTime() const
{
    return _dateTime;
}

std::ostream &operator<<(std::ostream &os, const Bill &bill)
{
    os << bill._id_Bill << ", ";
    os << bill._id_Customer << ", ";
    os << bill._cart.get_money();
    return os;
}