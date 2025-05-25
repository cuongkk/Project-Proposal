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

std::string ProductQueryBuilder::build()
{
    std::string query = baseQuery;
    if (!conditions.empty())
    {
        query += " WHERE " + joinConditions();
    }
    conditions.clear();
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