#include "Bill.h"

Bill::Bill()
{
    _id = 0;
    _id_Customer = 0;
    _totalCost = 0.0f;
}

Bill::~Bill() = default;

void Bill::confirmBill(Cart &&cart)
{
    _cart = std::move(cart);
    _totalCost = _cart.get_cost();
}

float Bill::get_totalCost() const
{
    return _totalCost;
}
