#include "LinkedList.h"

int LinkedList::_size = 0;

LinkedList::LinkedList()
{
    _pHead = nullptr;
    _pTail = nullptr;
}

void LinkedList::add_Head(std::unique_ptr<SanPham> value)
{
    Node *newNode = Node::CreateNode(std::move(value));
    newNode->pNext = _pHead;
    _pHead = newNode;
    if (_pTail == nullptr)
        _pTail = _pHead;
    _size++;
}

void LinkedList::add_Tail(std::unique_ptr<SanPham> value)
{
    Node *newNode = Node::CreateNode(std::move(value));
    if (_pTail != nullptr)
    {
        _pTail->pNext = newNode;
    }
    else
    {
        _pHead = newNode;
    }
    _pTail = newNode;
    _size++;
}

LinkedList::~LinkedList()
{
    Node *cur = _pHead;
    while (cur)
    {
        Node *tmp = cur;
        cur = cur->pNext;
        delete tmp;
    }
}

std::ostream &operator<<(std::ostream &os, const LinkedList &ll)
{
    Node *cur = ll._pHead;
    while (cur)
    {
        os << *cur << "\n";
        cur = cur->pNext;
    }
    return os;
}
