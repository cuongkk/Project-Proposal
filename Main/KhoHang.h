#ifndef KHOHANG_H
#define KHOHANG_H

#include "LinkedList.h"
#include <memory>

class KhoHang
{
private:
    LinkedList _sanpham;

public:
    KhoHang() = default;
    ~KhoHang() = default;

    void add(std::unique_ptr<SanPham>);
    void remove(const SanPham &);
    void updateQuantity(const SanPham &, const int &);
    std::unique_ptr<SanPham> getSanPham_from_id(const int &);
    friend std::ostream &operator<<(std::ostream &, const KhoHang &);
};
#endif
