#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Main.h"

template <typename T>
class LinkedList
{
protected:
    std::list<std::unique_ptr<T>> _list;

public:
    LinkedList() = default;
    ~LinkedList() = default;

    int get_size() const;
    std::string get_money() const;

    void push_back(std::unique_ptr<T> sp);
    void add_Head(std::unique_ptr<T>);
    void add_Tail(std::unique_ptr<T>);
    void add_Head_to_Cart(std::unique_ptr<T>);
    void add_Tail_to_Cart(std::unique_ptr<T>);
    const std::list<std::unique_ptr<T>> &get_Item() const;

    void remove_from_KhoHang(std::unique_ptr<T>);
    void remove_from_Cart(std::unique_ptr<T>);

    LinkedList<T> &operator=(const LinkedList &other);
};

template <typename T>
std::ostream &operator<<(std::ostream &, const LinkedList<T> &);

#include "LinkedList.tpp"

#endif
