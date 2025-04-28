#include "LinkedList.h"

int LinkedList::_size = 0;

LinkedList::LinkedList()
{
    _pHead = nullptr;
    _pTail = nullptr;
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

int LinkedList::get_size()
{
    return _size;
}

float LinkedList::get_cost() const
{
    float totalCost = 0;
    Node *cur = _pHead;
    while (cur)
    {
        totalCost = totalCost + cur->data->clone();
        cur = cur->pNext;
    }
    return totalCost;
}

Node *LinkedList::get_Head() const
{
    return _pHead;
}
void LinkedList::add_Head_to_KhoHang(std::unique_ptr<SanPham> sp)
{
    Node *newNode = Node::CreateNode(std::move(sp));
    newNode->pNext = _pHead;
    _pHead = newNode;
    if (_pTail == nullptr)
        _pTail = _pHead;
    _size++;
}

void LinkedList::add_Tail_to_KhoHang(std::unique_ptr<SanPham> sp)
{
    Node *newNode = Node::CreateNode(std::move(sp));
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

void LinkedList::add_Head_to_Cart(std::unique_ptr<SanPham> sp)
{
    Node *cur = _pHead;
    while (cur)
    {
        if (cur->data && *cur->data == *sp)
        {
            cur->data->set_quantity(cur->data->get_quantity() + 1);
            return;
        }
        cur = cur->pNext;
    }

    sp->set_quantity(1);
    Node *newNode = Node::CreateNode(std::move(sp));
    newNode->pNext = _pHead;
    _pHead = newNode;
    if (_pTail == nullptr)
        _pTail = _pHead;
    _size++;
}

void LinkedList::add_Tail_to_Cart(std::unique_ptr<SanPham> sp)
{
    Node *cur = _pHead;
    while (cur)
    {
        if (cur->data && *cur->data == *sp)
        {
            cur->data->set_quantity(cur->data->get_quantity() + 1);
            return;
        }
        cur = cur->pNext;
    }
    sp->set_quantity(1);
    Node *newNode = Node::CreateNode(std::move(sp));
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

void LinkedList::remove(const int &id)
{
    if (_pHead == nullptr)
    {
        return;
    }

    Node *cur = _pHead;
    Node *prev = nullptr;

    while (cur)
    {
        if (cur->data && cur->data->get_id() == id)
        {
            if (prev == nullptr)
            {
                _pHead = cur->pNext;
            }
            else
            {
                prev->pNext = cur->pNext;
            }

            if (cur == _pTail)
            {
                _pTail = prev;
            }

            delete cur;
            _size--;
            return;
        }

        prev = cur;
        cur = cur->pNext;
    }
}

void LinkedList::operator=(const LinkedList &ll)
{
    Node *cur = ll._pHead;
    while (cur)
    {
        add_Tail_to_Cart(cur->data->clone());
        cur = cur->pNext;
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
