#include "ProductQueryBuilder.h"

ProductQueryBuilder &ProductQueryBuilder::filterById(const std::string &id)
{
    if (id != "")
    {
        conditions.push_back("id = '" + id + "'");
    }
    return *this;
}

ProductQueryBuilder &ProductQueryBuilder::filterByName(const std::string &name)
{
    if (name != "")
    {
        conditions.push_back("name LIKE N'%" + name + "%'");
    }
    return *this;
}

ProductQueryBuilder &ProductQueryBuilder::filterByCategory(const std::string &category)
{
    if (category != "")
    {
        conditions.push_back("category = N'" + category + "'");
    }
    return *this;
}

ProductQueryBuilder &ProductQueryBuilder::filterByPriceRange(const std::string &minPrice, const std::string &maxPrice)
{
    if (!minPrice.empty() && !maxPrice.empty())
    {
        conditions.push_back("price BETWEEN " + minPrice + " AND " + maxPrice);
    }
    return *this;
}

ProductQueryBuilder &ProductQueryBuilder::updateName(const std::string &name)
{
    if (!name.empty())
    {
        updateFields.push_back("name = N'" + name + "'");
    }
    return *this;
}

ProductQueryBuilder &ProductQueryBuilder::updateInf(const std::string &inf)
{
    if (!inf.empty())
    {
        updateFields.push_back("inf = N'" + inf + "'");
    }
    return *this;
}

ProductQueryBuilder &ProductQueryBuilder::updatePrice(const std::string &price)
{
    if (!price.empty())
    {
        updateFields.push_back("price = " + price);
    }
    return *this;
}

ProductQueryBuilder &ProductQueryBuilder::updateDiscount(const std::string &discount)
{
    if (!discount.empty())
    {
        updateFields.push_back("discount = " + discount);
    }
    return *this;
}

ProductQueryBuilder &ProductQueryBuilder::updateQuantity(const std::string &quantity)
{
    if (!quantity.empty())
    {
        updateFields.push_back("quantity = " + quantity);
    }
    return *this;
}

ProductQueryBuilder &ProductQueryBuilder::updateManufactureDate(const std::string &manufactureDate)
{
    if (!manufactureDate.empty())
    {
        updateFields.push_back("manufacture_date = '" + manufactureDate + "'");
    }
    return *this;
}

ProductQueryBuilder &ProductQueryBuilder::updateExpiryDate(const std::string &expiryDate)
{
    if (!expiryDate.empty())
    {
        updateFields.push_back("expiry_date = '" + expiryDate + "'");
    }
    return *this;
}

ProductQueryBuilder &ProductQueryBuilder::updateImagePath(const std::string &imagePath)
{
    if (!imagePath.empty())
    {
        updateFields.push_back("image_path = '" + imagePath + "'");
    }
    return *this;
}

std::string ProductQueryBuilder::buildFilter()
{
    std::string query = baseQueryFilter;
    if (!conditions.empty())
    {
        query += " WHERE " + joinConditions();
    }
    conditions.clear();
    return query;
}

std::string ProductQueryBuilder::buildUpdate()
{
    std::string query = baseQueryUpdate;
    if (!updateFields.empty())
    {
        query += joinUpdateFields();
    }
    updateFields.clear();
    return query;
}

std::string ProductQueryBuilder::joinConditions()
{
    std::string joinedConditions;
    for (const auto &condition : conditions)
    {
        if (!joinedConditions.empty())
        {
            joinedConditions += " AND ";
        }
        joinedConditions += condition;
    }
    return joinedConditions;
}

std::string ProductQueryBuilder::joinUpdateFields()
{
    std::string joinedUpdateFields;
    for (const auto &field : updateFields)
    {
        if (!joinedUpdateFields.empty())
        {
            joinedUpdateFields += ", ";
        }
        joinedUpdateFields += field;
    }
    return joinedUpdateFields;
}