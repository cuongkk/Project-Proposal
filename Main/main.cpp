#include "Main.h"
#include "UserManagement.h"
#include "BillManagement.h"
#include "KhoHang.h"
#include "Bill.h"
#include "Cart.h"
#include "ThucAn.h"
#include "ThucUong.h"
#include "Admin.h"
#include "Customer.h"

KhoHang khoHang;
UserManagement userManagement;
BillManagement billManagement;

std::vector<int> SanPham::_id_counter_sp = {0};
std::vector<int> User::_id_counter_user = {0};
std::vector<int> Bill::_id_counter_bill = {0};

int main()
{
    auto admin = std::make_unique<Admin>("admin", "admin123", "admin");
    auto customer = std::make_unique<Customer>("Nguyen Van B", "abc@gmail.com", "0123456789", "1000000", "VND", "customer",
                                               "customet123", "customer");

    userManagement.add(std::move(admin));
    userManagement.add(std::move(customer));

    std::cout << userManagement << "\n";

    auto thucAn = std::make_unique<ThucAn>("Bánh mì", "Bánh mì thịt", "Thức ăn", 100, "5000", "VND", 0.1, "2025-04-01", "2025-04-10");
    auto thucUong = std::make_unique<ThucUong>("Trà sữa", "Trà sữa matcha", "Thức uống", 1, "25000", "VND", 0.05, "2025-04-01", "2025-04-15");

    khoHang.add(std::move(thucAn));
    khoHang.add(std::move(thucUong));

    Cart cart;
    cart.add(khoHang, khoHang.getSanPham_from_id("SP0001"));
    cart.add(khoHang, khoHang.getSanPham_from_id("SP0002"));

    Bill bill;
    std::cout << cart << "\n";

    std::unique_ptr<Bill> bill1 = bill.confirmBill(userManagement, "US0002", std::move(cart));
    billManagement.add(std::move(bill1));
    std::cout << billManagement << "\n";

    std::cout << userManagement << "\n";

    std::string keyWord =  "";
    int optionSearch = 0;
    //1: search by name, information, id
    //2: search by type
    //3: sort by lower cost
    //4: sort by higher cost
    std::cout << "Menu tìm kiếm: \n";
    std::cout << "1. Tìm kiếm theo tên, thông tin, id\n";
    std::cout << "2. Tìm kiếm theo loại (Thức ăn, Thức uống)\n";
    std::cout << "3. Lọc theo mức giá nhập vào trở xuống\n";
    std::cout << "4. Lọc theo mức giá nhập vào trở lên\n";
    std::cout << "Nhập lựa chọn: ";
    std::cin >> optionSearch;
    std::cin.ignore();
    std::cout << "Nhập từ khóa hoặc con số: ";
    std::getline(std::cin, keyWord);
    khoHang.search(keyWord, optionSearch);

    return 0;
}
