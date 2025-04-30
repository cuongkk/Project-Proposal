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

bool Cart::add(KhoHang &khoHang, std::unique_ptr<SanPham> sp)
{
    SanPham *spOrigin = sp->get_origin();
    if (spOrigin->get_quantity() > 0)
    {
        khoHang.updateQuantity(*sp->get_origin(), 1);
        _sanpham.add_Tail_to_Cart(std::move(sp));
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
    _sanpham.remove_from_Cart(std::move(sp));
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