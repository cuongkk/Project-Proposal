#ifndef PRODUCTQUERYBUILDER_H
#define PRODUCTQUERYBUILDER_H

#include <string>
#include <vector>
#include <iostream>
class ProductQueryBuilder
{
private:
    std::string baseQuery = "SELECT id, name, inf, category, price, discount, quantity, manufacture_date, expiry_date, image_path FROM Products";
    std::vector<std::string> conditions;

public:
    ProductQueryBuilder &filterById(const std::string &id);

    ProductQueryBuilder &filterByName(const std::string &name);

    ProductQueryBuilder &filterByCategory(const std::string &category);

    ProductQueryBuilder &filterByPriceRange(const std::string &minPrice, const std::string &maxPrice);

    std::string build();

private:
    std::string joinConditions();
};
#endif