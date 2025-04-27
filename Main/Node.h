#ifndef NODE_H
#define NODE_H

#include "SanPham.h"
#include <memory>

class Node
{
public:
    std::unique_ptr<SanPham> data;
    Node *pNext;

    Node(std::unique_ptr<SanPham> sp);
    ~Node();
    static Node *CreateNode(std::unique_ptr<SanPham> sp);
    friend std::ostream &operator<<(std::ostream &, const Node &);
};

#endif
