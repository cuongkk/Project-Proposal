#include "LinkedList.h"
#include <iostream>

template <typename T>
int LinkedList<T>::get_size() const
{
    return _list.size();
}

template <typename T>
float LinkedList<T>::get_cost() const
{
    float totalCost = 0;
    for (const auto &item : _list)
    {
        totalCost = totalCost + *item;
    }
    return totalCost;
}

template <typename T>
void LinkedList<T>::add_Head(std::unique_ptr<T> sp)
{
    _list.push_front(std::move(sp));
}

template <typename T>
void LinkedList<T>::add_Tail(std::unique_ptr<T> sp)
{
    _list.push_back(std::move(sp));
}

template <typename T>
void LinkedList<T>::add_Head_to_Cart(std::unique_ptr<T> sp)
{
    for (auto &item : _list)
    {
        if (*item == *sp)
        {
            item->set_quantity(item->get_quantity() + 1);
            return;
        }
    }
    sp->set_quantity(1);
    _list.push_front(std::move(sp));
}

template <typename T>
void LinkedList<T>::add_Tail_to_Cart(std::unique_ptr<T> sp)
{
    for (auto &item : _list)
    {
        if (*item == *sp)
        {
            item->set_quantity(item->get_quantity() + 1);
            return;
        }
    }
    sp->set_quantity(1);
    _list.push_back(std::move(sp));
}

template <typename T>
const std::list<std::unique_ptr<T>> &LinkedList<T>::get_SanPham() const
{
    return _list;
}

template <typename T>
void LinkedList<T>::remove_from_KhoHang(std::unique_ptr<T> sp)
{
    for (auto item = _list.begin(); item != _list.end(); ++item)
    {
        if (**item == *sp)
        {
            (*item)->set_counter(get_counter_from_id("SP", (*item)->get_id()) - 1);
            _list.erase(item);
            return;
        }
    }
}

template <typename T>
void LinkedList<T>::remove_from_Cart(std::unique_ptr<T> sp)
{
    for (auto item = _list.begin(); item != _list.end(); ++item)
    {
        if (**item == *sp)
        {
            (*item)->set_quantity((*item)->get_quantity() - 1);
            if ((*item)->get_quantity() == 0)
            {
                _list.erase(item);
            }
            return;
        }
    }
}

template <typename T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &other)
{
    if (this != &other)
    {
        _list.clear();
        for (const auto &item : other._list)
        {
            _list.push_back(item->clone());
        }
    }
    return *this;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const LinkedList<T> &ll)
{
    for (const auto &item : ll.get_SanPham())
    {
        os << *item;
        os << "\n";
    }
    return os;
}
