#ifndef KHOHANG_H
#define KHOHANG_H

#include "Main.h"
#include "SanPham.h"
#include "LinkedList.h"
#include <memory>
#include <regex>

class KhoHang
{
private:
    LinkedList<SanPham> _sanpham;

public:
    KhoHang() = default;
    ~KhoHang() = default;

    void search(const std::string &keyword, const int &optionSearch);
    void add(std::unique_ptr<SanPham>);
    void remove(std::unique_ptr<SanPham>);
    void updateQuantity(const SanPham &, const int &);
    std::unique_ptr<SanPham> getSanPham_from_id(const std::string &);
    friend std::ostream &operator<<(std::ostream &, const KhoHang &);
};
#endif
