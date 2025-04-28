#ifndef KHOHANG_H
#define KHOHANG_H

#include "LinkedList.h"
class KhoHang
{
private:
    LinkedList _sanpham;

public:
    KhoHang();
    ~KhoHang();
    void add(std::unique_ptr<SanPham> sp);
    void remove(const int &);
    std::unique_ptr<SanPham> getSanPham_from_id(const int &);
    void print();
};
#endif