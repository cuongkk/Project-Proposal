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

Bill::Bill(const std::string &id_Customer, Cart &&cart, const DateTime &dateTime)
    : _dateTime(dateTime)
{

    _id_Bill = set_id("BI", _id_counter_bill);
    _id_Customer = id_Customer;
    _cart = std::move(cart);
    _totalCost = _cart.get_money();
}

std::unique_ptr<Bill> Bill::clone()
{
    return std::make_unique<Bill>(*this);
}

Bill *Bill::get_origin()
{
    return _origin;
}

void Bill::set_counter(const int &index)
{
    _id_counter_bill[index] = 0;
}

std::string Bill::get_id() const
{
    return _id_Bill;
}

std::string Bill::get_id_Customer() const
{
    return _id_Customer;
}

std::unique_ptr<Bill> Bill::confirmBill(UserManagement &userManagement, std::string &id_user, const DateTime &dateTime)

{
    auto Customer = userManagement.getUser_from_id(id_user);
    auto cart = Customer->get_cart();
    Customer->get_origin()->_cart.clear();
    Customer->get_origin()->set_money(std::to_string(stoll(Customer->get_money()) - stoll(cart.get_money())));
    auto bill = std::make_unique<Bill>(id_user, std::move(cart), dateTime);
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