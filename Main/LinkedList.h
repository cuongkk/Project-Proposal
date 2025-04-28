#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <memory>

class LinkedList
{
protected:
    Node *_pHead, *_pTail;
    static int _size;

public:
    LinkedList();
    ~LinkedList();

    static int get_size();
    float get_cost() const;

    Node *get_Head() const;
    void add_Head(std::unique_ptr<SanPham>);
    void add_Tail(std::unique_ptr<SanPham>);
    void remove(const int &);

    void operator=(const LinkedList &);

    friend std::ostream &operator<<(std::ostream &, const LinkedList &);
};

#endif
