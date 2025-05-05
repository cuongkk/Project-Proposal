#include "Cart.h"

Cart::Cart()
{
}

Cart::~Cart()
{
}

Cart::Cart(const std::string &id_Customer)
{
    _id_Customer = id_Customer;
}
int Cart::get_size() const
{
    return _list.get_size();
}

std::string Cart::get_money() const
{
    return _list.get_money();
}

std::unique_ptr<Cart> Cart::clone() const
{
    auto new_cart = std::make_unique<Cart>();
    for (const auto &item : this->_list.get_Item())
    {
        new_cart->_list.push_back(item->clone());
    }
    return new_cart;
}

bool Cart::add(KhoHang &khoHang, std::unique_ptr<SanPham> sp)
{
    SanPham *spOrigin = sp->get_origin();
    if (spOrigin->get_quantity() > 0)
    {
        khoHang.updateQuantity(*spOrigin, 1);
        _list.add_Tail_to_Cart(std::move(sp));
        return true;
    }
    else if (spOrigin->get_quantity() == 0)
    {
        return false;
    }
    return true;
}

void Cart::remove(KhoHang &khoHang, std::unique_ptr<SanPham> sp)
{
    SanPham *spOrigin = sp->get_origin();
    khoHang.updateQuantity(*spOrigin, -1);
    _list.remove_from_Cart(std::move(sp));
}

void Cart::operator=(const Cart &cart)
{
    _list = cart._list;
}
std::ostream &operator<<(std::ostream &os, const Cart &cart)
{
    os << cart._list;
    return os;
}