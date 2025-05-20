#pragma once
#include <vector>
#include <string>
#include "Product.h"

class ProductRepository {
public:
    virtual std::vector<Product> getProducts(const std::string& query) = 0;
    virtual ~ProductRepository() = default;
};
