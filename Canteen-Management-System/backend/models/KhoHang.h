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
    static std::vector<int> _id_counter_sp;

    KhoHang() = default;
    ~KhoHang() = default;

    void add(std::shared_ptr<Product>);
    void remove(std::shared_ptr<Product>);
    void updateQuantity(const Product &, const int &);
    const LinkedList<Product> &getProduct() const;
    std::unique_ptr<Product> getProduct_from_id(const std::string &);
    friend std::ostream &operator<<(std::ostream &, const KhoHang &);

    std::vector<std::string> get_name_product() const;

    KhoHang &search_category(const std::string &);
    KhoHang &search_price(const std::string &, const std::string &);

    void clear();
    // bool isExpired(const DateTime &expiryDateStr) const;
    // bool containsKeyword(const std::string &keyword, const int &option, const Product &sp) const;
    // std::vector<std::string> search(const std::string &keyword, const int &optionSearch);
};
#endif
