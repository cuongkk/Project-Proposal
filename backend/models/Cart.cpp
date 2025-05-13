#include "Cart.h"

Cart::Cart()
{
}

Cart::~Cart()
{
}

Cart::Cart(const Cart &cart)
{
    _id_Customer = cart._id_Customer;
    _list = cart._list;
}

Cart::Cart(Cart &&cart) noexcept
{
    _id_Customer = std::move(cart._id_Customer);
    _list = std::move(cart._list);
}

Cart::Cart(const std::string &id_Customer, const LinkedList<Product> &list)
{
    _id_Customer = id_Customer;
    _list = std::move(list);
}

int Cart::get_size() const
{
    return _list.get_size();
}

std::string Cart::get_money() const
{
    return _list.get_money();
}

LinkedList<Product> Cart::get_list() const
{
    return _list;
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

bool Cart::add(std::unique_ptr<Product> sp)
{
    Product *spOrigin = sp->get_origin();
    if (spOrigin->get_quantity() > 0)
    {
        _list.add_Tail_to_Cart(std::move(sp));
        return true;
    }
    else if (spOrigin->get_quantity() == 0)
    {
        return false;
    }
    return true;
}

void Cart::remove(std::unique_ptr<Product> sp)
{
    Product *spOrigin = sp->get_origin();
    _list.remove_from_Cart(std::move(sp));
}

void Cart::clear()
{
    _list.clear();
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