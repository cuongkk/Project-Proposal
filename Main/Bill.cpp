#include "Bill.h"

Bill::Bill()
    : _id(0), _id_Customer(0), _cart(), _totalCost(0.0f)
{
}

Bill::~Bill() = default;

void Bill::confirmBill(Cart &&cart)
{
    _cart = std::move(cart);
    _totalCost = _cart.get_cost();

    // for (const auto &sp : _cart._sanpham.get_SanPham())
    // {
    //     if (sp)
    //     {
    //         khoHang.updateQuantity(sp->get_id(), sp->get_quantity());
    //     }
    // }
}

float Bill::get_totalCost() const
{
    return _totalCost;
}
