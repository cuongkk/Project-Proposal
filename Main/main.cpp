#include <iostream>
#include "KhoHang.h"
#include "Bill.h"
#include "Cart.h"
#include "ThucAn.h"
#include "ThucUong.h"

KhoHang khoHang;
int main()
{
    auto thucAn = std::make_unique<ThucAn>("Bánh mì", "Bánh mì thịt", 1, "Thức ăn", 100, 5000, 0.1, "2025-04-01", "2025-04-10");
    auto thucUong = std::make_unique<ThucUong>("Trà sữa", "Trà sữa matcha", 2, "Thức uống", 200, 25000, 0.05, "2025-04-01", "2025-04-15");

    khoHang.add(std::move(thucAn));
    khoHang.add(std::move(thucUong));
    Cart cart;
    cart.addSanPham(khoHang.getSanPham_from_id(1));
    // Bill bill;
    // bill.confirmBill(khoHang, std::move(cart));
    khoHang.print();

    return 0;
}
