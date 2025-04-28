#include "KhoHang.h"

KhoHang::KhoHang()
{
}

KhoHang::~KhoHang()
{
}

void KhoHang::add(std::unique_ptr<SanPham> sp)
{
    _sanpham.add_Tail_to_KhoHang(std::move(sp));
}

void KhoHang::remove(const int &id)
{
    _sanpham.remove(id);
}

void KhoHang::updateQuantity(const int &id, const int &quantity)
{
    Node *cur = _sanpham.get_Head();
    while (cur)
    {
        if (cur->data->get_id() == id)
        {
            int newQuantity = cur->data->get_quantity() - quantity;
            if (newQuantity > 0)
            {
                cur->data->set_quantity(newQuantity);
            }
            else
            {
                remove(cur->data->get_id());
            }
            return;
        }
        cur = cur->pNext;
    }
}

std::unique_ptr<SanPham> KhoHang::getSanPham_from_id(const int &id)
{
    Node *cur = _sanpham.get_Head();
    while (cur)
    {
        if (cur->data->get_id() == id)
        {
            return cur->data->clone();
        }
        cur = cur->pNext;
    }
    return 0;
}
void KhoHang::print()
{
    std::cout << _sanpham;
}