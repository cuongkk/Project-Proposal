#ifndef KHOHANG_H
#define KHOHANG_H

#include "Main.h"
#include "SanPham.h"
#include "LinkedList.h"

class KhoHang
{
private:
    LinkedList<SanPham> _sanpham;

public:
    KhoHang() = default;
    ~KhoHang() = default;

    void add(std::unique_ptr<SanPham>);
    void remove(std::unique_ptr<SanPham>);
    void updateQuantity(const SanPham &, const int &);
    std::unique_ptr<SanPham> getSanPham_from_id(const std::string &);
    friend std::ostream &operator<<(std::ostream &, const KhoHang &);

    bool isExpired(const std::string &expiryDateStr) const;
    bool containsKeyword(const std::string &keyword, const int &option, const SanPham &sp) const;
    std::vector<std::string> search(const std::string &keyword, const int &optionSearch);
};
#endif
