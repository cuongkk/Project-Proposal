#include <iostream>
#include "LinkedList.h"
#include "ThucAn.h"
#include "ThucUong.h"

int main()
{
    auto thucAn = std::make_unique<ThucAn>("Bánh mì", "Bánh mì thịt", 1, "Thức ăn", 100, 5000, 10, "2025-04-01", "2025-04-10");
    auto thucUong = std::make_unique<ThucUong>("Trà sữa", "Trà sữa matcha", 2, "Thức uống", 200, 25000, 5, "2025-04-01", "2025-04-15");

    LinkedList list;
    list.add_Head(std::move(thucAn));
    list.add_Tail(std::move(thucUong));
    std::cout << list;

    return 0;
}
