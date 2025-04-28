#include "Node.h"

Node::Node(std::unique_ptr<SanPham> sp)
    : data(std::move(sp)), pNext(nullptr)
{
}
Node::~Node()
{
}

Node *Node::CreateNode(std::unique_ptr<SanPham> sp)
{
    return new Node(std::move(sp));
}

std::ostream &operator<<(std::ostream &os, const Node &node)
{
    if (node.data != nullptr)
    {
        os << *(node.data);
    }
    return os;
}
