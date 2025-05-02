// #include "Crow/include/crow.h"
// #include <vector>
// #include <string>

// struct SanPham
// {
//     int id;
//     std::string ten;
//     double gia;
// };

// std::vector<SanPham> danh_sach_san_pham = {
//     {1, "Trà sữa", 25000},
//     {2, "Bánh mì", 15000},
//     {3, "Cà phê", 20000}};

// int main()
// {
//     crow::SimpleApp app;

//     // Đường dẫn là chuỗi ký tự thông thường, không cần khai báo là crow::url
//     CROW_ROUTE(app, "/api/sanpham")
//     ([]()
//      {
//          crow::json::wvalue x;
//          for (size_t i = 0; i < danh_sach_san_pham.size(); ++i)
//          {
//              x[i]["id"] = danh_sach_san_pham[i].id;
//              x[i]["ten"] = danh_sach_san_pham[i].ten;
//              x[i]["gia"] = danh_sach_san_pham[i].gia;
//          }
//          return x; // Trả về dữ liệu dưới dạng JSON
//      });

//     app.port(18080).multithreaded().run();
// }
