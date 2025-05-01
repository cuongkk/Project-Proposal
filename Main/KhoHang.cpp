#include "KhoHang.h"
#include <iostream>

void KhoHang::add(std::unique_ptr<SanPham> sp)
{
    _sanpham.add_Tail_to_KhoHang(std::move(sp));
}

void KhoHang::remove(std::unique_ptr<SanPham> sp)
{
    _sanpham.remove_from_KhoHang(std::move(sp));
}

void KhoHang::updateQuantity(const SanPham &sp, const int &quantity)
{
    for (auto &item : _sanpham.get_SanPham())
    {
        if (*item == sp)
        {
            int newQuantity = item->get_quantity() - quantity;
            if (newQuantity >= 0)
            {
                item->set_quantity(newQuantity);
            }
            return;
        }
    }
}

std::unique_ptr<SanPham> KhoHang::getSanPham_from_id(const std::string &id)
{
    for (const auto &sp : _sanpham.get_SanPham())
    {
        if (sp->get_id() == id)
        {
            return sp->clone();
        }
    }
    return nullptr;
}

void KhoHang::search(const std::string &keyword, const int& optionSearch) 
{   
    bool found = false;
    std::cout << "Tìm kiếm sản phẩm với từ khóa: " << keyword << "\n";
    for(const auto &sp : _sanpham.get_SanPham())
    {
        if (sp->containsKeyword(keyword, optionSearch))
        {
            found = true;
            std::cout << *sp << "\n";
        }
    }
    if (!found)
    {
        std::cout << "Không tìm thấy sản phẩm nào với từ khóa: " << keyword << "\n";
    }
}
std::ostream &operator<<(std::ostream &os, const KhoHang &KhoHang)
{
    os << KhoHang._sanpham;
    return os;
}
