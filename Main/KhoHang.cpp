#include "KhoHang.h"

KhoHang::KhoHang()
{
}

KhoHang::~KhoHang()
{
}

void KhoHang::add(std::unique_ptr<SanPham> sp)
{
    _sanpham.add_Tail(std::move(sp));
}

void KhoHang::remove(const int &id)
{
    _sanpham.remove(id);
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
    }
    return 0;
}
void KhoHang::print()
{
    std::cout << _sanpham;
}