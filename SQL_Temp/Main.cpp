#include "ProductQueryBuilder.h"
#include "ProductRepositoryImpl_MySQL.h"
#include <iostream>

int main() {
    ProductQueryBuilder builder;
    std::string query = builder.filterByCategory("Electronics")
                               .filterByMaxPrice(500)
                               .build();

    

    std::cout << "Query: " << query << "\n";

    // ProductRepositoryImpl_MySQL repo("tcp://127.0.0.1:3306", "root", "2005", "shop");
    // auto products = repo.getProducts(query);

    // for (const auto& p : products) {
    //     std::cout << p.getId() << " | " << p.getName() << " | $" << p.getPrice() << " | " << p.getCategory() << "\n";
    // }

    return 0;
}
