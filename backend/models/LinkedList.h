#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Main.h"

template <typename T>
class LinkedList
{
protected:
    std::list<std::shared_ptr<T>> _list;

public:
    LinkedList() = default;
    ~LinkedList() = default;

    auto begin();
    auto end();
    auto begin() const;
    auto end() const;
    int get_size() const;
    std::string get_money() const;

    void push_back(std::shared_ptr<T> sp);
    void add_Head(std::shared_ptr<T>);
    void add_Tail(std::shared_ptr<T>);
    void add_Head_to_Cart(std::shared_ptr<T>);
    void add_Tail_to_Cart(std::shared_ptr<T>);
    const std::list<std::shared_ptr<T>> &get_Item() const;
    void clear();

    bool check_username(const std::string &);
    bool check_name(const std::string &);
    bool check_product(const T &sp) const;

    void remove_from_KhoHang(std::shared_ptr<T>);
    void remove_from_Cart(std::shared_ptr<T>);
    LinkedList<T> &operator=(const LinkedList &other);
};

template <typename T>
std::ostream &operator<<(std::ostream &, const LinkedList<T> &);

#include "LinkedList.tpp"

#endif
