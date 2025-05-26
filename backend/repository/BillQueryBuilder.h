#ifndef BILLQUERYBUILDER_H
#define BILLQUERYBUILDER_H

#include <string>
#include <vector>

class BillQueryBuilder
{
private:
    std::string baseQueryFilter = "SELECT id_Bill, id_User, totalCost, paid_date FROM Bill";
    std::vector<std::string> conditions;

public:
    BillQueryBuilder &filterByIdBill(const std::string &id);
    BillQueryBuilder &filterByIdCustomer(const std::string &id_Customer);
    BillQueryBuilder &filterByTotalCost(const std::string &totalCost);
    BillQueryBuilder &filterByPaidDate(const std::string &paid_date);
    std::string buildFilter();

private:
    std::string joinConditions();
};
#endif