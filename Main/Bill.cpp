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

    Node *current = cart._sanpham.get_Head();
    while (current != nullptr)
    {
        if (current->data)
        {
            SanPham *spOrigin = current->data->get_origin();
            if (spOrigin)
            {
                khoHang.remove(spOrigin->get_id());
            }
        }
        else
        {
            std::cerr << "Warning: Product data is null!" << std::endl;
        }

        current = current->pNext;
    }
    std::cout << cart;
    _cart = cart;
    std::cout << _cart;
    _totalCost = _cart.get_cost();
}
