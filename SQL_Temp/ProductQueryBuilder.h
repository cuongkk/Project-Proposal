#pragma once
#include <vector>
#include <string>

class ProductQueryBuilder {
private:
    std::vector<std::string> conditions;

public:
    ProductQueryBuilder& filterByCategory(const std::string& category) {
        conditions.push_back("category = '" + category + "'");
        return *this;
    }

    ProductQueryBuilder& filterByMaxPrice(double maxPrice) {
        conditions.push_back("price <= " + std::to_string(maxPrice));
        return *this;
    }

    ProductQueryBuilder& filterByMinPrice(double minPrice) {
        conditions.push_back("price >= " + std::to_string(minPrice));
        return *this;
    }

    std::string build() const {
        std::string query = "SELECT id, name, price, category FROM Products";
        if (!conditions.empty()) {
            query += " WHERE " + joinConditions();
        }
        return query;
    }

    std::string Insert(const std::string& name, double price, const std::string& category) const {
        return "INSERT INTO Products (name, price, category) VALUES ('" + name + "', " + std::to_string(price) + ", '" + category + "')";
    }

    std::string Delete() const {
        std::string query = "DELETE FROM Products";
        if (!conditions.empty()) {
            query += " WHERE " + joinConditions();
        }
        return query;    
    } 

    std::string Update(const std::string& column, const std::string& value) const {
        std::string query = "UPDATE Products SET " + column + " = '" + value + "'";
        if (!conditions.empty()) {
            query += " WHERE " + joinConditions();
        }
        return query;
    }

    std::string Update(const std::string& column, double value) const {
        std::string query = "UPDATE Products SET " + column + " = " + std::to_string(value);
        if (!conditions.empty()) {
            query += " WHERE " + joinConditions();
        }
        return query;
    }

    std::string Update(const std::string& column, int value) const {
        std::string query = "UPDATE Products SET " + column + " = " + std::to_string(value);
        if (!conditions.empty()) {
            query += " WHERE " + joinConditions();
        }
        return query;
    }



private:
    std::string joinConditions() const {
        std::string result = conditions[0];
        for (size_t i = 1; i < conditions.size(); ++i) {
            result += " AND " + conditions[i];
        }
        return result;
    }
};
