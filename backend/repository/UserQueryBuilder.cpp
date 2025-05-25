#include "UserQueryBuilder.h"

UserQueryBuilder &UserQueryBuilder::filterById(const std::string &id)
{
    if (id != "")
    {
        conditions.push_back("id = '" + id + "'");
    }

    return *this;
}

UserQueryBuilder &UserQueryBuilder::filterByUsername(const std::string &username)
{
    if (username != "")
    {
        conditions.push_back("username = N'" + username + "'");
    }
    return *this;
}

UserQueryBuilder &UserQueryBuilder::filterByPassword(const std::string &password)
{
    if (password != "")
    {
        conditions.push_back("password = '" + password + "'");
    }
    return *this;
}

UserQueryBuilder &UserQueryBuilder::filterByName(const std::string &name)
{
    if (name != "")
    {
        conditions.push_back("name LIKE N'%" + name + "%'");
    }
    return *this;
}

UserQueryBuilder &UserQueryBuilder::filterByEmail(const std::string &email)
{
    if (email != "")
    {
        conditions.push_back("email = '" + email + "'");
    }
    return *this;
}

UserQueryBuilder &UserQueryBuilder::filterByPhoneNumber(const std::string &phoneNumber)
{
    if (phoneNumber != "")
    {
        conditions.push_back("phoneNumber = '" + phoneNumber + "'");
    }
    return *this;
}

UserQueryBuilder &UserQueryBuilder::updateFullname(const std::string &fullname)
{
    if (!fullname.empty())
    {
        updateFields.push_back("fullname = '" + fullname + "'");
    }
    return *this;
}

UserQueryBuilder &UserQueryBuilder::updateEmail(const std::string &email)
{
    if (!email.empty())
    {
        updateFields.push_back("email = '" + email + "'");
    }
    return *this;
}

UserQueryBuilder &UserQueryBuilder::updatePhoneNumber(const std::string &phoneNumber)
{
    if (!phoneNumber.empty())
    {
        updateFields.push_back("phoneNumber = '" + phoneNumber + "'");
    }
    return *this;
}

UserQueryBuilder &UserQueryBuilder::updateMoney(const std::string &money)
{
    if (!money.empty())
    {
        updateFields.push_back("money = '" + money + "'");
    }
    return *this;
}

std::string UserQueryBuilder::buildFilter()
{
    std::string query = baseQueryFilter;
    if (!conditions.empty())
    {
        query += " WHERE " + joinConditions();
    }
    conditions.clear();
    return query;
}

std::string UserQueryBuilder::buildUpdate()
{
    std::string query = baseQueryUpdate;
    if (!updateFields.empty())
    {
        query += joinUpdateFields();
    }
    updateFields.clear();
    conditions.clear();
    return query;
}
std::string UserQueryBuilder::joinConditions()
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

std::string UserQueryBuilder::joinUpdateFields()
{
    std::string joinedFields;
    for (const auto &field : updateFields)
    {
        if (!joinedFields.empty())
        {
            joinedFields += ", ";
        }
        joinedFields += field;
    }
    return joinedFields;
}