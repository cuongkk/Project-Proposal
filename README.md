## 👥 Thành viên thực hiện

Dự án được thực hiện bởi nhóm gồm 2 thành viên:

| Họ và tên         | MSSV                   |
|-------------------|------------------------------|
| Nguyễn Tuấn Cường      | 23120224 |
| Trần Gia Cường     | 23120225 |

Chúng em cùng nhau lên ý tưởng, triển khai các chức năng cơ bản và nâng cao, đồng thời hoàn thiện báo cáo và giao diện người dùng để phục vụ đồ án môn học Lập trình Hướng đối tượng.


# 🍱 Hệ thống Quản lý Căn tin (Canteen Management System)

Đây là một hệ thống quản lý căn tin đơn giản nhưng có thể mở rộng, được xây dựng bằng **ngôn ngữ C++ theo hướng lập trình hướng đối tượng (OOP)**. Dự án mô phỏng các chức năng cơ bản và nâng cao của một hệ thống đặt món ăn tại căn tin trường học hoặc doanh nghiệp.

---

## 🚀 Chức năng chính

### ✅ Các chức năng cơ bản
- **Quản lý người dùng**: Phân quyền người dùng (Admin và Khách hàng), đăng nhập hệ thống.
- **Quản lý thực đơn**: Thêm, sửa, xoá và hiển thị danh sách món ăn.
- **Đặt món**: Khách hàng có thể đặt món và xem đơn hàng.
- **Quản lý giỏ hàng**: Thêm/xoá món ăn trước khi thanh toán.
- **Tạo hoá đơn**: Tính tổng tiền và in ra thông tin đơn hàng.

---

## 💡 Thiết kế theo hướng OOP

Hệ thống được thiết kế dựa trên các đặc điểm của lập trình hướng đối tượng:

| Đặc điểm OOP       | Áp dụng trong dự án                                        |
|--------------------|-------------------------------------------------------------|
| **Encapsulation**  | Đóng gói dữ liệu trong các lớp `User`, `FoodItem`, `Cart`, `Order`... |
| **Inheritance**    | `Admin` và `Customer` kế thừa từ lớp cha `User`             |
| **Polymorphism**   | Giao diện `PaymentMethod` cho nhiều loại thanh toán khác nhau |
| **Abstraction**    | Ẩn chi tiết xử lý qua các interface và lớp trừu tượng       |

---

## 🔧 Các chức năng nâng cao (hiện tại hoặc có thể thêm vào)

### 🧾 Hệ thống mã giảm giá
- Áp dụng khuyến mãi phần trăm hoặc theo số tiền.
- Dễ dàng mở rộng bằng class trừu tượng `Coupon` và tính đa hình.

### 🔍 Tìm kiếm và lọc món ăn
- Lọc theo danh mục, giá, món chay/mặn,...
- Sử dụng **Strategy Pattern** để thay đổi bộ lọc linh hoạt.

### 📦 Quản lý kho hàng
- Mỗi món ăn có số lượng tồn kho.
- Tự động kiểm tra trước khi xác nhận đơn hàng.

### 💳 Tích hợp thanh toán
- Hỗ trợ nhiều hình thức: Tiền mặt, thẻ, ví điện tử.
- Áp dụng giao diện `PaymentMethod` để xử lý linh hoạt.

### 📈 Thống kê - báo cáo
- Thống kê doanh thu, món ăn bán chạy,...
- Có thể triển khai qua lớp `ReportService`.

### 🛡️ Phân quyền người dùng (RBAC)
- Hệ thống phân quyền theo vai trò: `Admin`, `Khách hàng`, `Nhân viên`.
- Áp dụng kiểm soát truy cập ở tầng xử lý nghiệp vụ.

### 💬 Đánh giá & nhận xét món ăn
- Khách hàng có thể đánh giá và để lại bình luận.
- Hiển thị trung bình sao trên thực đơn.

---

## 🛠️ Công nghệ sử dụng

Hệ thống quản lý căn tin được xây dựng với các công nghệ sau:

- **Ngôn ngữ lập trình C++**: Dùng để xử lý logic nghiệp vụ, quản lý dữ liệu và kết nối đến cơ sở dữ liệu.
- **MySQL**: Được sử dụng làm hệ quản trị cơ sở dữ liệu để lưu trữ thông tin về người dùng, món ăn, đơn hàng,...
- **HTML/CSS với JavaScript**: Dùng để xây dựng giao diện người dùng, hiển thị thông tin và tương tác với hệ thống.
- **RESTful API**: Được sử dụng để giao tiếp giữa frontend (giao diện người dùng) và backend (xử lý logic nghiệp vụ).
- **Crow**: Một web framework cho C++ được sử dụng để xây dựng các API một cách hiệu quả và đơn giản.

## ✅ Đảm bảo chất lượng phần mềm

Hệ thống được xây dựng với các biện pháp đảm bảo chất lượng nhằm tăng độ tin cậy, dễ bảo trì và mở rộng trong tương lai:

- **Kiểm thử chức năng (Function Testing)**  
  Kiểm thử thủ công các chức năng chính như đăng nhập, đặt món, tạo hóa đơn, phân quyền để đảm bảo đúng yêu cầu đề ra.

- **Kiểm thử giao diện người dùng (UI Testing)**  
  Đảm bảo giao diện hiển thị đúng, dễ sử dụng và thân thiện với người dùng.

- **Quản lý mã nguồn rõ ràng**  
  Các chức năng được chia theo từng lớp/layer (`User`, `SanPham`, `Bill`,...) giúp mã nguồn dễ đọc, dễ bảo trì và phát triển.

- **Tuân thủ nguyên tắc SOLID trong thiết kế hướng đối tượng (OOP)**  
  Giúp hệ thống dễ mở rộng, dễ tái sử dụng và giảm phụ thuộc giữa các thành phần.

- **Xử lý lỗi và thông báo rõ ràng**  
  Cung cấp thông báo phù hợp khi xảy ra lỗi như: không đủ số lượng món, đăng nhập sai, món ăn không tồn tại,...


## 📚 Nguồn tham khảo

- [Canteen Management System in C with MySQL – CodeWithC](https://www.codewithc.com/c-program-canteen-management-system-c-mysql/)

