#pragma once
#include <string>

class Product {
private:
    std::string id;
    std::string name;
    double price;
    std::string category;

public:
    Product(std::string id, std::string name, double price, std::string category)
        : id(id), name(name), price(price), category(category) {}

    std::string getId() const { return id; }
    std::string getName() const { return name; }
    double getPrice() const { return price; }
    std::string getCategory() const { return category; }
};
