#include "BillQueryBuilder.h"

BillQueryBuilder &BillQueryBuilder::filterByIdBill(const std::string &id)
{
    if (!id.empty())
    {
        conditions.push_back("id_Bill = '" + id + "'");
    }
    return *this;
}

BillQueryBuilder &BillQueryBuilder::filterByIdCustomer(const std::string &id_Customer)
{
    if (!id_Customer.empty())
    {
        conditions.push_back("id_User = '" + id_Customer + "'");
    }
    return *this;
}

BillQueryBuilder &BillQueryBuilder::filterByTotalCost(const std::string &totalCost)
{
    if (!totalCost.empty())
    {
        conditions.push_back("totalCost = '" + totalCost + "'");
    }
    return *this;
}

BillQueryBuilder &BillQueryBuilder::filterByPaidDate(const std::string &paid_date)
{
    if (!paid_date.empty())
    {
        conditions.push_back("paid_date = '" + paid_date + "'");
    }
    return *this;
}

std::string BillQueryBuilder::buildFilter()
{
    std::string query = baseQueryFilter;
    if (!conditions.empty())
    {
        query += " WHERE " + joinConditions();
    }
    conditions.clear();
    return query;
}

std::string BillQueryBuilder::joinConditions()
{
    std::string result;
    for (const auto &condition : conditions)
    {
        if (!result.empty())
        {
            result += " AND ";
        }
        result += condition;
    }
    return result;
}
