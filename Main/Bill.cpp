#include "Bill.h"

Bill::Bill()
{
    _id = 0;
    _id_Customer = 0;
    _cart = Cart();
    _totalCost = 0;
}

Bill::~Bill()
{
}

void Bill::confirmBill(KhoHang &khoHang, Cart &&cart)
{
    _cart = cart;
    _totalCost = _cart.get_cost();
    Node *current = cart._sanpham.get_Head();
    while (current != nullptr)
    {
        if (current->data)
        {
            {
                khoHang.updateQuantity(current->data->get_id(), current->data->get_quantity());
            }

            current = current->pNext;
        }
    }
}
float Bill::get_totalCost() const
{
    return _totalCost;
}