#include "Bill.h"

Bill::Bill()
{
    _id_Bill = "";
    _id_Customer = "";
    _totalCost = 0.0f;
}

Bill::~Bill() = default;

Bill::Bill(const std::string &id_Customer, Cart &&cart)
{

    _id_Bill = set_id("BI", _id_counter_bill);
    _id_Customer = id_Customer;
    _cart = std::move(cart);
    _totalCost = _cart.get_money();
}

std::unique_ptr<Bill> Bill::clone()
{
    auto new_bill = std::make_unique<Bill>();
    new_bill->_id_Bill = this->_id_Bill;
    new_bill->_id_Customer = this->_id_Customer;
    new_bill->_cart = *(this->_cart.clone()); // sử dụng clone() của Cart
    new_bill->_totalCost = this->_totalCost;
    new_bill->_origin = this;
    return new_bill;
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

std::unique_ptr<Bill> Bill::confirmBill(UserManagement &userManagement, const std::string &id_Customer, Cart &&cart)
{
    auto bill1 = std::unique_ptr<Bill>(new Bill());

    if (0 < cart.get_size())
    {
        if (userManagement.getUser_from_id(id_Customer) >= std::stoll(cart.get_money()))
        {
            User *userOrigin = userManagement.getUser_from_id(id_Customer)->get_origin();
            userOrigin->set_money(userManagement.getUser_from_id(id_Customer) - cart.get_money());
            _totalCost = _cart.get_money();
            auto bill = std::make_unique<Bill>(id_Customer, std::move(cart));
            return bill;
        }
        else
        {
        }
    }
    return bill1;
}
std::string Bill::get_totalCost() const
{
    return _totalCost;
}

std::ostream &operator<<(std::ostream &os, const Bill &bill)
{
    os << bill._id_Bill << ", ";
    os << bill._id_Customer << ", ";
    os << bill._cart.get_money();
    return os;
}