#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <list>
#include <memory>
#include "SanPham.h"

class LinkedList
{
protected:
    std::list<std::unique_ptr<SanPham>> _sanpham;

public:
    LinkedList() = default;
    ~LinkedList() = default;

    int get_size() const;
    float get_cost() const;

    void add_Head_to_KhoHang(std::unique_ptr<SanPham>);
    void add_Tail_to_KhoHang(std::unique_ptr<SanPham>);
    void add_Head_to_Cart(std::unique_ptr<SanPham>);
    void add_Tail_to_Cart(std::unique_ptr<SanPham>);
    const std::list<std::unique_ptr<SanPham>> &get_SanPham() const;

    void remove_from_KhoHang(const SanPham &);
    void remove_from_Cart(std::unique_ptr<SanPham>);

    LinkedList &operator=(const LinkedList &other);

    friend std::ostream &operator<<(std::ostream &os, const LinkedList &ll);
};

#endif
