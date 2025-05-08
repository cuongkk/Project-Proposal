#include "LinkedList.h"

template <typename T>
int LinkedList<T>::get_size() const
{
    return _list.size();
}

template <typename T>
std::string LinkedList<T>::get_money() const
{
    std::string totalCost = "";
    for (const auto &item : _list)
    {
        totalCost = totalCost + *item;
    }
    return totalCost;
}

template <typename T>
void LinkedList<T>::push_back(std::unique_ptr<T> sp)
{
    _list.push_back(std::move(sp));
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
const std::list<std::unique_ptr<T>> &LinkedList<T>::get_Item() const
{
    return _list;
}

template <typename T>
bool LinkedList<T>::check_username(const std::string &username)
{
    for (const auto &item : _list)
    {
        if (item->get_username() == username)
        {
            return false;
        }
    }
    return true;
}

template <typename T>
bool LinkedList<T>::check_name(const std::string &name)
{
    for (const auto &item : _list)
    {
        if (item->get_name() == name)
        {
            return false;
        }
    }
    return true;
}

template <typename T>
bool LinkedList<T>::check_product(const T &sp) const
{
    for (const auto &item : _list)
    {
        if (*item == sp)
        {
            return false;
        }
    }
    return true;
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
    for (const auto &item : ll.get_Item())
    {
        os << *item;
        os << "\n";
    }
    return os;
}
