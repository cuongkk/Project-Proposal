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

---

**Ghi chú**: Mọi đánh giá xin dựa trên chức năng hiện có, tư duy thiết kế hệ thống và khả năng mở rộng của dự án.
