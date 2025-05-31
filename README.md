# PROJECT CANTEEN MANAGEMENT

## Thành viên nhóm
| Họ tên             | MSSV      | Vai trò        |
|--------------------|-----------|----------------|
| Nguyễn Tuấn Cường  | 23120224  | Nhóm trưởng    |
| Trần Gia Cường     | 23120225  | Thành viên     |

---

## Phân công công việc

### Nguyễn Tuấn Cường
- Thiết kế Frontend để hiển thị giao diện người dùng (đăng kí tài khoản, mua sản phẩm, xem giỏ hàng, hóa đơn,...)
- Bổ sung database
- Tạo lớp `ThucAn`, `ThucUong` để quản lí sản phẩm, tạo lớp trừu tượng `SanPham` để ứng dụng tính đa hình. Tạo lớp `KhoHang` để quản lí sản phẩm
- Tạo lớp `Customer`, Admin để quản lí người dùng, với lớp trừu tượng `User` và lớp `UserManagement` để quản lí User
- Tạo Cart để thêm xóa sản phẩm trước khi mua
- Tạo Bill để thanh toán và `BillManagement` để quản lí Bill
- Sử dụng std::move() để tối ưu bộ nhớ, sử dụng get_clone() để thao tác trên bản sao tránh gây lỗi. Dùng get_Origin() để kiểm tra bản gốc cũng như cập nhật
- Xây dựng mối quan hệ giữa các lớp
 + Customer và Admin được phân quyền rõ ràng (sẽ cập nhật thêm)
 + Khi thêm SanPham vào Cart sẽ kiểm tra số lượng trước khi thêm. Khi thêm vào thì sẽ tự động cập nhập lại số lượng sản phẩm trong `KhoHang`.
 + Khi Bill được thanh toán sẽ lưu lại trong `BillManagement` và tự động cập nhật số tiền của Customer

- Link Commit: https://github.com/cuongkk/Canteen-Management-System/commits/TuanCuong

### Trần Gia Cường
- Xây dựng cơ sở dữ liệu, sử dụng SQL để lưu trữ dữ liệu
- Xây dựng chức năng tìm kiếm:
  - Tìm kiếm sản phẩm trong `KhoHang`, người dùng trong `UserManagement`, hóa đơn trong `BillManagement`.
  - Hỗ trợ tìm kiếm theo nhiều tiêu chí (ID, tên, loại,...) sử dụng `regex`.
  - Trả về ID đối tượng để phục vụ hiển thị giao diện.
- Bổ sung cho lớp SanPham áp dụng trừu tượng.
- Viết hàm `main` để kiểm thử toàn bộ chương trình:
  - Thêm/xóa sản phẩm vào `KhoHang`, `Cart`, `Bill`, sau đó tìm kiếm.
  - Thêm `Admin`, `Customer` vào `UserManagement`, kiểm tra tính năng tìm kiếm.
- Class Diagram và mô tả các lớp

- Link Commit: https://github.com/cuongkk/Canteen-Management-System/commits/cuong225

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
| Nguyễn Tuấn Cường  | 100      | 
| Trần Gia Cường     | 100      |

## Tỉ lệ hoàn thành đồ án : 100%

## Các extension và thư viện cài thêm:
MySQL:
https://dev.mysql.com/downloads/connector/cpp/
https://dev.mysql.com/downloads/workbench/

Extension: 
- `Live Server` (để hiển thị Web)

Thư viện (nằm trong thư mục `external`):
- `crow`
- `asio`

Chuẩn bị: 
- Tạo database trong `mySQL` bằng cách sử dụng file `Sql Canteen.sql` trong đồ án
- Sửa đổi mật khẩu trong `route.cpp`

Cách chạy
- Xóa thư mục build và thực thi câu lệnh:
mkdir build
cd build
cmake .. -G "Visual Studio 17 2022" -A x64

- Sau đó vào thư mục build và thực thi câu lệnh:
cmake --build . --config Release

- Thực hiện câu lệnh: .\Release\server.exe

- Chọn (Open Live Server) file `show-product.html`

---

## Class Diagram và Mô tả
title Class Diagram - Full System

======================= USER & ROLE ========================= 

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

======================= PRODUCT =========================

abstract class Product {
  - _id_sp: string
  - _quantity: int
  - _discount: string
  - _money: Money
  - _manufacture_Date: DateTime
  - _expiry_Date: DateTime
  - _imagePath: string
  - _origin: Product*
  + clone(): unique_ptr<Product>
  + get_name(): string
  + get_inf(): string
  + ...
}

class Food {
  - _name: string
  - _inf: string
  + clone(): unique_ptr<Product>
  + ...
}

class Drink {
  - _name: string
  - _inf: string
  + clone(): unique_ptr<Product>
  + ...
}

Product <|-- Food
Product <|-- Drink

======================= KHOHANG =========================

class KhoHang {
  - _Product: LinkedList<Product>
  + add(shared_ptr<Product>)
  + remove(shared_ptr<Product>)
  + updateQuantity(Product, int)
  + getProduct(): const LinkedList<Product>&
  + getProduct_from_id(string): unique_ptr<Product>
  + get_name_product(): vector<string>
  + search_category(string): KhoHang&
  + search_price(string, string): KhoHang&
  + clear()
}

KhoHang --> "1..*" Product

======================= CART ========================= 

class Cart {
  - _id_Customer: string
  - _list: LinkedList<Product>
  + add(unique_ptr<Product>)
  + get_money(): string
  + ...
}

Customer --> Cart
User --> Cart
Cart --> "1..*" Product

======================= BILL ========================= 

class Bill {
  - _id_Bill: string
  - _id_Customer: string
  - _cart: Cart
  - _totalCost: string
  - _dateTime: DateTime
  + clone(): shared_ptr<Bill>
  + confirmBill(string, User*, DateTime): shared_ptr<Bill>
  + ...
}

class BillManagement {
  - _bill: LinkedList<Bill>
  + add(shared_ptr<Bill>)
  + getBill_from_id(string): shared_ptr<Bill>
  + ...
}

Bill --> Cart
Bill --> DateTime
Bill --> Customer
BillManagement --> "1..*" Bill

---
## Hệ thống Quản lý Canteen

## 📌 Tổng quan
Hệ thống mô phỏng quản lý cửa hàng với các chức năng như:
- Quản lý người dùng (Admin, Customer)
- Quản lý giỏ hàng (Cart)
- Quản lý sản phẩm (Food, Drink)
- Quản lý hóa đơn (Bill)

---

## Cấu trúc Lớp

### 🧍‍♂️ User (trừu tượng)
Lớp cơ sở cho tất cả người dùng.

#### Thuộc tính chính:
- ID, username, password, tên, hình ảnh
- Cart cá nhân
- Dùng con trỏ gốc (`_origin`) để hỗ trợ clone

#### Phương thức thuần ảo:
- `clone()`, `print()`, `get_cart()`, `get_money()`...
- `get_fullname()`, `get_email()`, `get_phoneNumber()`

---

### 👤 Admin
Kế thừa từ `User`, dùng cho người quản trị hệ thống.

- Cài đặt đầy đủ các phương thức từ `User`
- Không có thêm thuộc tính

---

### 👥 Customer
Kế thừa từ `User`, đại diện cho khách hàng.

#### Thêm thuộc tính:
- `fullname`, `email`, `phoneNumber`, `money`

---

### 🛒 Cart
Giỏ hàng cá nhân của người dùng.

#### Thuộc tính:
- ID khách hàng
- Danh sách `Product` (Food/Drink)

#### Chức năng:
- `add()`, `remove()`, `clear()`
- `get_money()` tính tổng tiền sản phẩm

---

### 📦 Product (trừu tượng)
Lớp cơ sở cho thực phẩm, đồ uống.

#### Thuộc tính:
- ID, số lượng, giảm giá, giá tiền (`Money`)
- Ngày sản xuất, hết hạn (`DateTime`)
- Hình ảnh sản phẩm

#### Phương thức thuần ảo:
- `clone()`, `get_name()`, `get_inf()`

---

### 🍔 Food / 🍹 Drink
Kế thừa từ `Product`, đại diện thực phẩm và đồ uống.

- Thêm tên và mô tả (`_name`, `_inf`)
- Ghi đè `clone()`, `print()`

---

### KhoHang 
Quản lý toàn bộ sản phẩm trong kho.

#### Thuộc tính:
- `_Product`: danh sách `Product` (dạng `LinkedList`)
- `_id_counter_sp`: sinh mã sản phẩm

#### Chức năng:
- `add(product)`, `remove(product)`
- `updateQuantity(product, new_quantity)`
- `getProduct()`: lấy toàn bộ danh sách
- `getProduct_from_id(id)`: lấy sản phẩm theo mã
- `search_category(category)`: lọc theo loại (nếu có danh mục)
- `search_price(min, max)`: lọc sản phẩm theo giá
- `get_name_product()`: danh sách tên
- `clear()`: xóa sạch kho

---

### 🧾 Bill
Hóa đơn ghi nhận lịch sử mua hàng.

#### Thuộc tính:
- ID hóa đơn, ID khách, giỏ hàng, tổng tiền, ngày tạo

#### Chức năng:
- `clone()`, `confirmBill()`, `get_totalCost()`

---

### BillManagement
Quản lý danh sách hóa đơn.

#### Chức năng:
- `add()`, `remove()`, `getBill_from_id()`, `getBill_from_id_Customer()`
- `clear()`

---

## 📎 Phụ thuộc
- `Main.h`, `Money.h`, `DateTime.h`, `LinkedList.h`
- `Product.h`, `Drink.h`, `Food.h`, `Bill.h`, `Cart.h`, `Customer.h`

---
