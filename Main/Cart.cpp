#include "Cart.h"

Cart::Cart()
{
}

Cart::~Cart()
{
}

int Cart::get_size() const
{
    return _sanpham.get_size();
}

float Cart::get_cost() const
{
    return _sanpham.get_cost();
}

void Cart::add(std::unique_ptr<SanPham> sp)
{
    _sanpham.add_Tail_to_Cart(std::move(sp));
}

void Cart::remove(const int &id)
{
    _sanpham.remove(id);
}

void Cart::operator=(const Cart &cart)
{
    _sanpham = cart._sanpham;
}
std::ostream &operator<<(std::ostream &os, const Cart &cart)
{
    os << cart._sanpham;
    return os;
}