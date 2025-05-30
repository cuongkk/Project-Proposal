# PROJECT CANTEEN MANAGEMENT

## Thành viên nhóm
| Họ tên             | MSSV      | Vai trò        |
|--------------------|-----------|----------------|
| Nguyễn Tuấn Cường  | 23120224  | Nhóm trưởng    |
| Trần Gia Cường     | 23120225  | Thành viên     |

---

## Phân công công việc

### Nguyễn Tuấn Cường
- Tạo lớp ThucAn, ThucUong để quản lí sản phẩm, tạo lớp trừu tượng SanPham để ứng dụng tính đa hình. Tạo lớp KhoHang để quản lí sản phẩm
- Tạo lớp Customer, Admin để quản lí người dùng, với lớp trừu tượng User và lớp UserManagement để quản lí User
- Tạo Cart để thêm xóa sản phẩm trước khi mua
- Tạo Bill để thanh toán và BillManagement để quản lí Bill
- Sử dụng std::move() để tối ưu bộ nhớ, sử dụng get_clone() để thao tác trên bản sao tránh gây lỗi. Dùng get_Origin() để kiểm tra bản gốc cũng như cập nhật
- Xây dựng mối quan hệ giữa các lớp
 + Customer và Admin được phân quyền rõ ràng (sẽ cập nhật thêm)
 + Khi thêm SanPham vào Cart sẽ kiểm tra số lượng trước khi thêm. Khi thêm vào thì sẽ tự động cập nhập lại số lượng sản phẩm trong KhoHang.
 + Khi Bill được thanh toán sẽ lưu lại trong BillManagement và tự động cập nhật số tiền của Customer

### Trần Gia Cường
- Xây dựng chức năng tìm kiếm:
  - Tìm kiếm sản phẩm trong `KhoHang`, người dùng trong `UserManagement`, hóa đơn trong `BillManagement`.
  - Hỗ trợ tìm kiếm theo nhiều tiêu chí (ID, tên, loại,...) sử dụng `regex`.
  - Trả về ID đối tượng để phục vụ hiển thị giao diện.
- Bổ sung cho lớp SanPham áp dụng trừu tượng.
- Viết hàm `main` để kiểm thử toàn bộ chương trình:
  - Thêm/xóa sản phẩm vào `KhoHang`, `Cart`, `Bill`, sau đó tìm kiếm.
  - Thêm `Admin`, `Customer` vào `UserManagement`, kiểm tra tính năng tìm kiếm.


---

## Tỉ lệ đóng góp vào dự án

| Thành viên         | Tỉ lệ đóng góp |
|--------------------|----------------|
| Nguyễn Tuấn Cường  | 100%            |
| Trần Gia Cường     | 100%            |

---

## Tỉ lệ điểm đề xuất



| Thành viên         | Điểm (%) |
|--------------------|----------|
| Nguyễn Tuấn Cường  | 100%     | 
| Trần Gia Cường     | 100%     |

## Tỉ lệ hoàn thành đồ án : 40%
- Còn tích hợp SQL vào quản lý dữ liệu
- Thiết kế giao diện sử dụng

---

## Mô tả yêu cầu và cách đánh giá

### 1. Thiết kế hệ thống hướng đối tượng
- Sử dụng kế thừa, đa hình (class `SanPham` làm cha cho `ThucAn` và `ThucUong`; class `User` làm cha cho `Admin` và `Customer`).
- Sử dụng get_clone() và get_Origin() để đảm bảo tính nguyên vẹn của dữ liệu 
- Quản lý danh sách sản phẩm, người dùng, hóa đơn bằng các lớp quản lý (`KhoHang`, `UserManagement`, `BillManagement`).

### 2. Tổ chức mã nguồn rõ ràng
- Mỗi lớp được tách riêng biệt theo chức năng.
- Hàm `main` viết để kiểm thử đầy đủ chức năng, dễ kiểm tra.

### 3. Kỹ thuật lập trình
- Sử dụng `std::move()` để tăng hiệu suất quản lý bộ nhớ.
- Kỹ thuật clone và origin giúp tránh lỗi dữ liệu khi thao tác đối tượng phức tạp.
- Regex tìm kiếm nâng cao, hỗ trợ linh hoạt theo nhiều tiêu chí.

### 4. Đảm bảo tính toàn vẹn dữ liệu
- Khi thêm sản phẩm vào giỏ hàng sẽ kiểm tra tồn kho.
- Khi thanh toán hóa đơn sẽ trừ tiền từ khách hàng và cập nhật tồn kho, đảm bảo dữ liệu nhất quán.

### 5. Khả năng mở rộng
- Dễ dàng mở rộng thêm loại sản phẩm khác (nhờ đa hình).
- Có thể thêm phân quyền nâng cao hoặc tính năng báo cáo trong tương lai.

### 6. Công việc tiếp theo 
- Sử dụng **RESTful API** để hỗ trỡ giao tiếp giữa người dùng
- Thiết kế giao diện với **HTML/CSS** và **JavaScript**
- Sử dụng **SQL Server** để quản lí dữ liệu, truy vẫn nhanh chóng
- Hoàn thiện models và mở rộng các tính năng


---

## Class Diagram
### User Management System
title Class Diagram - User Management System

class User {
  - _id_user: string
  - _username: string
  - _password: string
  - _name: string
  - _imagePath: string
  - _origin: User*
  - _cart: Cart
  --
  + User()
  + ~User()
  + get_id(): string
  + set_username(string): void
  + get_username(): string
  + set_password(string): void
  + get_password(): string
  + set_name(string): void
  + get_name(): string
  + set_imagePath(string): void
  + get_imagePath(): string
  + clone(): shared_ptr<User>
  + get_origin(): User*
  + set_fullname(string): void
  + get_fullname(): string
  + set_email(string): void
  + get_email(): string
  + set_phoneNumber(string): void
  + get_phoneNumber(): string
  + set_money(string): void
  + get_money(): string
  + get_cart(): Cart
  + print(ostream&): void
}

abstract class User

class Admin {
  + Admin()
  + ~Admin()
  + Admin(string, string, string, string, string)
  + clone(): shared_ptr<User>
  + get_origin(): User*
  + set_fullname(string): void
  + get_fullname(): string
  + set_email(string): void
  + get_email(): string
  + set_phoneNumber(string): void
  + get_phoneNumber(): string
  + set_money(string): void
  + get_money(): string
  + get_cart(): Cart
  + print(ostream&): void
}

class Customer {
  - _fullname: string
  - _email: string
  - _phoneNumber: string
  - _money: Money
  --
  + Customer()
  + ~Customer()
  + Customer(...): constructor overloads
  + clone(): shared_ptr<User>
  + get_origin(): User*
  + set_fullname(string): void
  + get_fullname(): string
  + set_email(string): void
  + get_email(): string
  + set_phoneNumber(string): void
  + get_phoneNumber(): string
  + set_money(string): void
  + get_money(): string
  + get_cart(): Cart
  + print(ostream&): void
}

class UserManagement {
  - _user: LinkedList<User>
  --
  + add(shared_ptr<User>): void
  + remove(shared_ptr<User>): void
  + get_username_user(): vector<string>
  + get_name_user(): vector<string>
  + get_email_user(): vector<string>
  + get_phoneNumber_user(): vector<string>
  + getUser_from_id(string): shared_ptr<User>
  + clear(): void
}

User <|-- Admin
User <|-- Customer
UserManagement --> "1..*" User

### Mô tả các lớp user:

## 🧱 Tổng quan
Hệ thống quản lý người dùng hỗ trợ nhiều loại người dùng như **Admin** và **Customer**. Được xây dựng dựa trên nguyên lý hướng đối tượng, hỗ trợ kế thừa, đa hình, clone đối tượng bằng `shared_ptr`.

---

## 📦 Danh sách các lớp

### 1. `User` (Lớp trừu tượng)
Lớp cơ sở định nghĩa thông tin và hành vi chung của người dùng.

#### Thuộc tính:
- `id_user`, `username`, `password`, `name`, `imagePath`
- `_origin`: con trỏ đến đối tượng gốc nếu clone
- `_cart`: giỏ hàng của người dùng

#### Phương thức thuần ảo:
- `clone()`, `get_origin()`
- `set/get_fullname()`, `set/get_email()`, `set/get_phoneNumber()`, `set/get_money()`
- `get_cart()`, `print(std::ostream&)`

---

### 2. `Admin` – Kế thừa từ `User`
Đại diện cho người quản trị hệ thống.

#### Điểm nổi bật:
- Cài đặt đầy đủ các hàm thuần ảo từ `User`
- Không có thêm thuộc tính riêng
- Ghi đè `clone`, `print`

---

### 3. `Customer` – Kế thừa từ `User`
Đại diện cho người dùng bình thường của hệ thống.

#### Thuộc tính bổ sung:
- `fullname`, `email`, `phoneNumber`, `money` (kiểu `Money`)

#### Điểm nổi bật:
- Hai constructor: cơ bản và đầy đủ
- Lưu thông tin chi tiết của người dùng
- Quản lý tiền (`Money`) riêng biệt

---

### 4. `UserManagement`
Quản lý danh sách người dùng bằng cấu trúc `LinkedList<User>`.

#### Phương thức chính:
- `add`, `remove` người dùng
- `get_username_user`, `get_name_user`, `get_email_user`, `get_phoneNumber_user`
- `getUser_from_id`: lấy người dùng theo ID
- `clear`: xóa toàn bộ danh sách

---

## 🔗 Quan hệ giữa các lớp
- `Admin`, `Customer` kế thừa từ `User`
- `UserManagement` quản lý danh sách các đối tượng `User` thông qua smart pointer

---

## 📎 Phụ thuộc
- `Main.h`, `Cart.h`, `Money.h`, `LinkedList.h`

---

## ✨ Mở rộng đề xuất
- Thêm xác thực đăng nhập
- Cho phép lọc người dùng theo quyền (admin/customer)
- Giao diện tương tác đơn giản (console hoặc GUI)



**Ghi chú**: Mọi đánh giá xin dựa trên chức năng hiện có, tư duy thiết kế hệ thống và khả năng mở rộng của dự án.