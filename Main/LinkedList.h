#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <memory> // Thêm để sử dụng std::unique_ptr

class LinkedList
{
protected:
    Node *_pHead, *_pTail;
    static int _size;

public:
    LinkedList();
    ~LinkedList();

    void add_Head(std::unique_ptr<SanPham> value);
    void add_Tail(std::unique_ptr<SanPham> value);
    friend std::ostream &operator<<(std::ostream &, const LinkedList &);
};

#endif
