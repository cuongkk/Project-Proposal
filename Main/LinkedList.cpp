#include "LinkedList.h"
#include <iostream>

int LinkedList::get_size() const
{
    return _sanpham.size();
}

float LinkedList::get_cost() const
{
    float totalCost = 0;
    for (const auto &item : _sanpham)
    {
        totalCost = totalCost + *item;
    }
    return totalCost;
}

void LinkedList::add_Head_to_KhoHang(std::unique_ptr<SanPham> sp)
{
    _sanpham.push_front(std::move(sp));
}

void LinkedList::add_Tail_to_KhoHang(std::unique_ptr<SanPham> sp)
{
    _sanpham.push_back(std::move(sp));
}

void LinkedList::add_Head_to_Cart(std::unique_ptr<SanPham> sp)
{
    for (auto &item : _sanpham)
    {
        if (*item == *sp)
        {
            item->set_quantity(item->get_quantity() + 1);
            return;
        }
    }
    sp->set_quantity(1);
    _sanpham.push_front(std::move(sp));
}

void LinkedList::add_Tail_to_Cart(std::unique_ptr<SanPham> sp)
{
    for (auto &item : _sanpham)
    {
        if (*item == *sp)
        {
            item->set_quantity(item->get_quantity() + 1);
            return;
        }
    }
    sp->set_quantity(1);
    _sanpham.push_back(std::move(sp));
}

const std::list<std::unique_ptr<SanPham>> &LinkedList::get_SanPham() const
{
    return _sanpham;
}

void LinkedList::remove_from_KhoHang(std::unique_ptr<SanPham> sp)
{
    for (auto item = _sanpham.begin(); item != _sanpham.end(); ++item)
    {
        if (**item == *sp)
        {
            (*item)->set_counter(get_counter_from_id("SP", (*item)->get_id()) - 1);
            _sanpham.erase(item);
            return;
        }
    }
}

void LinkedList::remove_from_Cart(std::unique_ptr<SanPham> sp)
{
    for (auto item = _sanpham.begin(); item != _sanpham.end(); ++item)
    {
        if (**item == *sp)
        {
            (*item)->set_quantity((*item)->get_quantity() - 1);
            if ((*item)->get_quantity() == 0)
            {
                _sanpham.erase(item);
            }
            return;
        }
    }
}
LinkedList &LinkedList::operator=(const LinkedList &other)
{
    if (this != &other)
    {
        _sanpham.clear();
        for (const auto &item : other._sanpham)
        {
            _sanpham.push_back(item->clone());
        }
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const LinkedList &ll)
{
    for (const auto &item : ll.get_SanPham())
    {
        os << *item;
        os << "\n";
    }
    return os;
}
