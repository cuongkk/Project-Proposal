#include <iostream>
#include "KhoHang.h"
#include "Bill.h"
#include "Cart.h"
#include "ThucAn.h"
#include "ThucUong.h"

KhoHang khoHang;
std::vector<int> SanPham::_id_counter = {0};
int main()
{
    auto thucAn = std::make_unique<ThucAn>("Bánh mì", "Bánh mì thịt", "Thức ăn", 100, 5000, 0.1, "2025-04-01", "2025-04-10");
    auto thucUong = std::make_unique<ThucUong>("Trà sữa", "Trà sữa matcha", "Thức uống", 1, 25000, 0.05, "2025-04-01", "2025-04-15");
    auto thucUong1 = std::make_unique<ThucUong>("Trà sữa", "Trà sữa matcha", "Thức uống", 1, 25000, 0.05, "2025-04-01", "2025-04-15");

    khoHang.add(std::move(thucAn));
    khoHang.add(std::move(thucUong));
    khoHang.add(std::move(thucUong1));

    khoHang.remove(khoHang.getSanPham_from_id("SP0002"));
    std::cout << khoHang << "\n";

    auto thucAn1 = std::make_unique<ThucAn>("Bánh mì", "Bánh mì thịt", "Thức ăn", 100, 5000, 0.1, "2025-04-01", "2025-04-10");
    khoHang.add(std::move(thucAn1));
    std::cout << khoHang << "\n";

    Cart cart;
    cart.add(khoHang, khoHang.getSanPham_from_id("SP0001"));
    cart.add(khoHang, khoHang.getSanPham_from_id("SP0002"));
    if (!cart.add(khoHang, khoHang.getSanPham_from_id("SP0002")))
    {
    }
    std::cout << khoHang << "\n";

    cart.remove(khoHang, khoHang.getSanPham_from_id("SP0002"));
    std::cout << khoHang << "\n";

    Bill bill;
    bill.confirmBill(std::move(cart));
    std::cout << "Bill: " << bill.get_totalCost() << "\n";
    return 0;
}
