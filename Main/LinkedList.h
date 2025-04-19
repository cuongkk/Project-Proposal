#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "SanPham.h"

class Node
{
    SanPham data;
    SanPham *pNext;
};

class LinkedList
{
private:
    Node *p_Head, p_Tail;
    static int _size;

public:
    LinkedList();
    void add_Head(const Node &, const Node &);
    void add_Tail(const Node &, const Node &);
};
#endif