#include "KhoHang.h"

void KhoHang::add(std::unique_ptr<SanPham> sp)
{
    _sanpham.add_Tail(std::move(sp));
}

void KhoHang::remove(std::unique_ptr<SanPham> sp)
{
    _sanpham.remove_from_KhoHang(std::move(sp));
}

void KhoHang::updateQuantity(const SanPham &sp, const int &quantity)
{
    for (auto &item : _sanpham.get_Item())
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
    for (const auto &sp : _sanpham.get_Item())
    {
        if (sp->get_id() == id)
        {
            return sp->clone();
        }
    }
    return nullptr;
}

bool KhoHang::containsKeyword(const std::string &keyword, const int& option, const SanPham& sp) const 
{
    std::regex pattern(keyword, std::regex_constants::icase);// không phân biệt hoa thường
    switch (option)
    {
        case 1: // search by name, information
            return std::regex_search(sp.get_name(), pattern) || std::regex_search(sp.get_inf(), pattern) || std::regex_search(sp.get_id(), pattern);
        case 2: // search by type
            return std::regex_search(sp.get_type(), pattern);
        case 3: // sort by lower cost 
            return (std::stof(sp.get_money().first) <= std::stof(keyword));
        case 4: // sort by higher cost
            return (std::stof(sp.get_money().first) >= std::stof(keyword));
        default:
            return false; // Invalid option
    }
}

void KhoHang::search(const std::string &keyword, const int& optionSearch) 
{   
    std::cout << "Danh sách sản phẩm tìm thấy:\n";
    for (const auto &item : _sanpham.get_Item())
    {
        if (containsKeyword(keyword, optionSearch, *item))
        {
            std::cout << *item << "\n";
        }
    }
}

std::ostream &operator<<(std::ostream &os, const KhoHang &KhoHang)
{
    os << KhoHang._sanpham;
    return os;
}
