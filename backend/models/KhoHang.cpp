#include "KhoHang.h"

void KhoHang::add(std::unique_ptr<Product> sp)
{
    _Product.add_Tail(std::move(sp));
}

void KhoHang::remove(std::unique_ptr<Product> sp)
{
    _Product.remove_from_KhoHang(std::move(sp));
}

void KhoHang::updateQuantity(const Product &sp, const int &quantity)
{
    for (auto &item : _Product.get_Item())
    {
        if (*item == sp)
        {
            int newQuantity = item->get_quantity() - quantity;
            if (newQuantity >= 0)
            {
                item->set_quantity(newQuantity);
            }
            return;
        }
    }
}

const LinkedList<Product> &KhoHang::getProduct() const
{
    return _Product;
}

std::vector<std::string> KhoHang::get_name_product() const
{
    std::vector<std::string> result;
    for (const auto &item : _Product.get_Item())
    {
        result.push_back(item->get_name());
    }
    return result;
}

std::unique_ptr<Product> KhoHang::getProduct_from_id(const std::string &id)
{
    for (const auto &sp : _Product.get_Item())
    {
        if (sp->get_id() == id)
        {
            return sp->clone();
        }
    }
    return nullptr;
}

// bool KhoHang::isExpired(const std::string &expiryDateStr) const
// {
//     // 1. Lấy ngày hệ thống
//     std::time_t now = std::time(nullptr);
//     std::tm *now_tm = std::localtime(&now);

//     // 2. Chuyển string -> std::tm
//     std::tm expiry_tm = {};
//     std::istringstream ss(expiryDateStr);
//     ss >> std::get_time(&expiry_tm, "%y-%m-%d"); // dd/mm/yyyy

//     if (ss.fail())
//     {
//         throw std::invalid_argument("Định dạng ngày không hợp lệ. Định dạng đúng: yy-mm-dd");
//         return false;
//     }

//     // 3. Chuyển về time_t để so sánh
//     std::time_t expiry_time = std::mktime(&expiry_tm);
//     std::time_t now_time = std::mktime(now_tm);

//     return now_time < expiry_time; // true nếu đã còn hạn
// }

bool KhoHang::containsKeyword(const std::string &keyword, const int &option, const Product &sp) const
{
    std::regex pattern(keyword, std::regex_constants::icase); // không phân biệt hoa thường
    switch (option)
    {
    case 1: // Tìm kiếm theo tên, thông tin, id
        return std::regex_search(sp.get_name(), pattern) || std::regex_search(sp.get_inf(), pattern) || std::regex_match(sp.get_id(), pattern);
    case 2: // Tìm kiếm sản phẩm theo mức giá nhập vào trở xuống
        return (std::stof(sp.get_money()) <= std::stof(keyword));
    case 3: // Tìm kiếm sản phẩm theo mức giá nhập vào trở lên
        return (std::stof(sp.get_money()) >= std::stof(keyword));
    case 4: // Tìm kiếm sản phẩm còn hàng
        return (sp.get_quantity() > 0);
    // case 5: // Tìm kiếm sản phẩm còn hạn sử dụng
    //     return isExpired(sp.get_expiry_Date());
    // case 6: // Tìm kiếm sản phẩm hết hạn sử dụng
    //     return !isExpired(sp.get_expiry_Date());
    default:
        return false; // Invalid option
    }
}

std::vector<std::string> KhoHang::search(const std::string &keyword, const int &optionSearch)
{
    bool found = false;
    std::vector<std::string> result;
    for (const auto &item : _Product.get_Item())
    {
        if (containsKeyword(keyword, optionSearch, *item))
        {
            found = true;
            result.push_back(item->get_id());
        }
    }
    if (!found)
    {
        std::cout << "Không tìm thấy sản phẩm nào.\n";
    }
    return result;
}

std::ostream &operator<<(std::ostream &os, const KhoHang &KhoHang)
{
    os << KhoHang._Product;
    return os;
}
