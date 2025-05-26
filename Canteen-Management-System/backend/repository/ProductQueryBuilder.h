#ifndef PRODUCTQUERYBUILDER_H
#define PRODUCTQUERYBUILDER_H

#include <string>
#include <vector>
#include <iostream>
class ProductQueryBuilder
{
private:
    std::string baseQueryFilter = "SELECT id, name, inf, category, price, discount, quantity, manufacture_date, expiry_date, image_path FROM Products";
    std::string baseQueryUpdate = "UPDATE Products SET ";
    std::vector<std::string> conditions;
    std::vector<std::string> updateFields;

public:
    ProductQueryBuilder &filterById(const std::string &id);
    ProductQueryBuilder &filterByName(const std::string &name);
    ProductQueryBuilder &filterByCategory(const std::string &category);
    ProductQueryBuilder &filterByPriceRange(const std::string &minPrice, const std::string &maxPrice);

    std::string buildFilter();

    ProductQueryBuilder &updateName(const std::string &name);
    ProductQueryBuilder &updateInf(const std::string &inf);
    ProductQueryBuilder &updatePrice(const std::string &price);
    ProductQueryBuilder &updateDiscount(const std::string &discount);
    ProductQueryBuilder &updateQuantity(const std::string &quantity);
    ProductQueryBuilder &updateManufactureDate(const std::string &manufactureDate);
    ProductQueryBuilder &updateExpiryDate(const std::string &expiryDate);
    ProductQueryBuilder &updateImagePath(const std::string &imagePath);

    std::string buildUpdate();

private:
    std::string joinConditions();
    std::string joinUpdateFields();
};
#endif