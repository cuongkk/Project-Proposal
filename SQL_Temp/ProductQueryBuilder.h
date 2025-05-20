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

private:
    std::string joinConditions() const {
        std::string result = conditions[0];
        for (size_t i = 1; i < conditions.size(); ++i) {
            result += " AND " + conditions[i];
        }
        return result;
    }
};
