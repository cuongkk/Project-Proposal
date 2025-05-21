#ifndef KHOHANG_H
#define KHOHANG_H

#include "Main.h"
#include "Product.h"
#include "LinkedList.h"

class KhoHang
{
private:
    LinkedList<Product> _Product;

public:
    KhoHang() = default;
    ~KhoHang() = default;

    void add(std::unique_ptr<Product>);
    void remove(std::unique_ptr<Product>);
    void updateQuantity(const Product &, const int &);
    const LinkedList<Product> &getProduct() const;
    std::unique_ptr<Product> getProduct_from_id(const std::string &);
    friend std::ostream &operator<<(std::ostream &, const KhoHang &);

    std::vector<std::string> get_name_product() const;
    // bool isExpired(const DateTime &expiryDateStr) const;
    bool containsKeyword(const std::string &keyword, const int &option, const Product &sp) const;
    std::vector<std::string> search(const std::string &keyword, const int &optionSearch);
};
#endif
