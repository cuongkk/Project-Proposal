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

    auto thucAn = std::make_unique<ThucAn>("Bánh mì", "Bánh mì thịt", "Thức ăn", 100, "5000", "VND", 0.1, "2025-04-01", "2025-09-10");
    auto thucUong = std::make_unique<ThucUong>("Trà sữa", "Trà sữa matcha", "Thức uống", 1, "25000", "VND", 0.05, "2025-04-01", "2025-04-15");
    auto thucUong1 = std::make_unique<ThucUong>("Trà sữa", "Trà sữa trân châu", "Thức uống", 5, "35000", "VND", 0.05, "2023-04-01", "2026-04-15");
    auto thucAn1 = std::make_unique<ThucAn>("Bánh mì", "Bánh mì chả cá", "Thức ăn", 50, "10000", "VND", 0.1, "2025-04-01", "2025-09-11");
    
    khoHang.add(std::move(thucAn));
    khoHang.add(std::move(thucUong));
    khoHang.add(std::move(thucUong1));
    khoHang.add(std::move(thucAn1));

    std::cout << "Kho hàng: \n";
    std::cout << khoHang << "\n";

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
    //1: Tìm kiếm theo tên, thông tin, id
    //2: Tìm kiếm sản phẩm theo loại (type)
    //3: Tìm kiếm các sản phẩm có giá thấp hơn giá nhập vào
    //4: Tìm kiếm các sản phẩm có giá cao hơn giá nhập vào
    //5: Tìm kiếm các sản phẩm còn hàng
    //6: Tìm kiếm các sản phẩm còn hạn sử dụng
    //7: Tìm kiếm các sản phẩm hết hạn sử dụng
    std::cout << "Menu tìm kiếm: \n";
    std::cout << "1. Tìm kiếm theo tên, thông tin, id\n";
    std::cout << "2. Tìm kiếm theo loại (Thức ăn, Thức uống)\n";
    std::cout << "3. Tìm kiếm sản phẩm theo mức giá nhập vào trở xuống\n";
    std::cout << "4. Tìm kiếm sản phẩm theo mức giá nhập vào trở lên\n";
    std::cout << "5. Tìm kiếm các sản phẩm còn hàng\n";
    std::cout << "6. Tìm kiếm các sản phẩm còn hạn sử dụng (yy-mm-dd)\n";
    std::cout << "7. Tìm kiếm các sản phẩm hết hạn sử dụng (yy-mm-dd)\n";
    //std::cout << "Nhập lựa chọn: ";
    //std::cin >> optionSearch;
    //std::cin.ignore();
    //std::cout << "Nhập từ khóa hoặc con số: ";
    //if(optionSearch < 5) std::getline(std::cin, keyWord);
    std::vector<std::string> result;
    keyWord = "Thức ăn";
    optionSearch = 2;
    result = khoHang.search(keyWord, optionSearch);
    std::cout << "2. Kết quả tìm kiếm: \n";
    for(const auto &id : result){
        std::cout << id << " || ";
    }
    std::cout << "\n";

    keyWord = "Trà sữa";
    optionSearch = 1;
    result = khoHang.search(keyWord, optionSearch);
    std::cout << "1. Kết quả tìm kiếm: \n";
    for(const auto &id : result){
        std::cout << id << " || ";
    }
    std::cout << "\n";
    
    keyWord = "26000";
    optionSearch = 3;
    result = khoHang.search(keyWord, optionSearch);
    std::cout << "3. Kết quả tìm kiếm: \n";
    for(const auto &id : result){
        std::cout << id << " || ";
    }
    std::cout << "\n";

    keyWord = "0";
    optionSearch = 5;
    result = khoHang.search(keyWord, optionSearch);
    std::cout << "5. Kết quả tìm kiếm: \n";
    for(const auto &id : result){
        std::cout << id << " || ";
    }
    std::cout << "\n";

    keyWord = "0";
    optionSearch = 6;
    result = khoHang.search(keyWord, optionSearch);
    std::cout << "6. Kết quả tìm kiếm: \n";
    for(const auto &id : result){
        std::cout << id << " || ";
    }
    std::cout << "\n";

    keyWord = "0";
    optionSearch = 7;
    result = khoHang.search(keyWord, optionSearch);
    std::cout << "7. Kết quả tìm kiếm: \n";
    for(const auto &id : result){
        std::cout << id << " || ";
    }

    return 0;
}
