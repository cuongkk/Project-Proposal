// #include "Main_all.h"

// KhoHang khoHang;
// UserManagement userManagement;
// BillManagement billManagement;

// int main()
// {
//     try
//     {
//         ProductRepositoryImpl_MySQL repo(
//             "tcp://127.0.0.1:3306", "root", "0328228324", "Canteen_Management");
//         repo.loadFromDatabase();

//         std::cout << "Danh sách sản phẩm hiện tại:\n";
//         for (const auto &product : repo.getAll())
//         {
//             std::cout << *product << "\n";
//         }
//         return 0;
//     }
//     catch (const sql::SQLException &e)
//     {
//         std::cerr << "Error: " << e.what() << "\n";
//         return 1;
//     }
//     catch (const std::exception &e)
//     {
//         std::cerr << "Error: " << e.what() << "\n";
//         return 1;
//     }
//     return 0;
// }
// // int main()
// // {
// //     auto admin = std::make_unique<Admin>("admin", "admin123", "admin");
// //     auto customer = std::make_unique<Customer>("customer", "customet123", "A", "Nguyen Van B", "abc@gmail.com", "0123456789", "1000000");

// //     userManagement.add(std::move(admin));
// //     userManagement.add(std::move(customer));

// //     std::cout << userManagement << "\n";

// //     DateTime date(2025, 4, 1);
// //     DateTime date1(2025, 4, 10);
// //     auto thucAn = std::make_unique<Food>("Bánh mì", "Bánh mì thịt", 100, "5000", 0.1, date, date1);
// //     auto thucUong = std::make_unique<Drink>("Trà sữa", "Trà sữa matcha", 1, "25000", 0.05, date, date1);

// //     khoHang.add(std::move(thucAn));
// //     khoHang.add(std::move(thucUong));

// //     Cart cart;
// //     cart.add(khoHang, khoHang.getProduct_from_id("SP0001"));
// //     cart.add(khoHang, khoHang.getProduct_from_id("SP0002"));

// //     Bill bill;
// //     std::cout << cart << "\n";

// //     std::unique_ptr<Bill> bill1 = bill.confirmBill(userManagement, "US0002", std::move(cart));
// //     billManagement.add(std::move(bill1));
// //     std::cout << billManagement << "\n";

// //     std::cout << userManagement << "\n";

// //     return 0;
// // }
