#include "UserManagement.h"

void UserManagement::add(std::unique_ptr<User> us)
{
    _user.add_Tail(std::move(us));
}

void UserManagement::remove(std::unique_ptr<User> us)
{
    _user.remove_from_KhoHang(std::move(us));
}

std::unique_ptr<User> UserManagement::getUser_from_id(const std::string &id)
{
    for (const auto &item : _user.get_Item())
    {
        if (item->get_id() == id)
        {
            return item->clone();
        }
    }
    return nullptr;
}


bool UserManagement::containsKeyword(const std::string &keyword, const int& option, const User& us) const 
{
    std::regex pattern("^" + keyword + "$", std::regex_constants::icase);// không phân biệt hoa thường
    switch (option)
    {
        case 1: // Tìm kiếm theo id người dùng
            return std::regex_match(us.get_id(), pattern);
        case 2: // Tìm kiếm theo tên người dùng
            return std::regex_match(us.get_username(), pattern);
        case 3: // Tìm kiếm theo loại người dùng (Khách hàng, Nhân viên)
            return std::regex_match(us.get_inf(), pattern);
        default:
            return false; // Invalid option
    }
}

std::vector<std::string> UserManagement::search(const std::string &keyword, const int& optionSearch) 
{   
    bool found = false;
    std::vector<std::string> result;
    for (const auto &user : _user.get_Item())
    {
        if (containsKeyword(keyword, optionSearch, *user))
        {
            found = true;
            result.push_back(user->get_id());
        }
    }
    if (!found)
    {
        std::cout << "Không tìm thấy sản phẩm nào.\n";
    }
    return result;
}


std::ostream &operator<<(std::ostream &os, const UserManagement &userManagement)
{
    os << userManagement._user;
    return os;
}
