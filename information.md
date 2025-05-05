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

- **C++** – Xử lý logic nghiệp vụ và kết nối cơ sở dữ liệu
- **MySQL** – Lưu trữ thông tin người dùng, món ăn, đơn hàng,...
- **HTML/CSS + Java (Servlet hoặc JSP)** – Giao diện người dùng
- (Tùy chọn) **Apache / Tomcat** – Chạy phần frontend động

---


