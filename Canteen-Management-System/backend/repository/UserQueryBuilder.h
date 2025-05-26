#ifndef USERQUERYBUILDER_H
#define USERQUERYBUILDER_H

#include <string>
#include <vector>
class UserQueryBuilder
{
private:
    std::string baseQueryFilter = "SELECT id, username, password, name, fullname, email, phoneNumber, money FROM User";
    std::string baseQueryUpdate = "UPDATE User SET ";
    std::vector<std::string> conditions;
    std::vector<std::string> updateFields;

public:
    UserQueryBuilder &filterById(const std::string &);
    UserQueryBuilder &filterByUsername(const std::string &);
    UserQueryBuilder &filterByPassword(const std::string &);
    UserQueryBuilder &filterByName(const std::string &);
    UserQueryBuilder &filterByEmail(const std::string &);
    UserQueryBuilder &filterByPhoneNumber(const std::string &);
    std::string buildFilter();

    UserQueryBuilder &updateFullname(const std::string &);
    UserQueryBuilder &updateEmail(const std::string &);
    UserQueryBuilder &updatePhoneNumber(const std::string &);
    UserQueryBuilder &updateMoney(const std::string &);
    std::string buildUpdate();

private:
    std::string joinConditions();
    std::string joinUpdateFields();
};
#endif