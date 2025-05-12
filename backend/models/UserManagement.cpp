#include "UserManagement.h"

void UserManagement::add(std::unique_ptr<User> us)
{
    _user.add_Tail(std::move(us));
}

void UserManagement::remove(std::unique_ptr<User> us)
{
    _user.remove_from_KhoHang(std::move(us));
}

std::vector<std::string> UserManagement::get_username_user() const
{
    std::vector<std::string> result;
    for (const auto &item : _user.get_Item())
    {
        result.push_back(item->get_username());
    }
    return result;
}

std::vector<std::string> UserManagement::get_name_user() const
{
    std::vector<std::string> result;
    for (const auto &item : _user.get_Item())
    {
        result.push_back(item->get_name());
    }
    return result;
}

std::vector<std::string> UserManagement::get_email_user() const
{
    std::vector<std::string> result;
    for (const auto &item : _user.get_Item())
    {
        result.push_back(item->get_email());
    }
    return result;
}

std::vector<std::string> UserManagement::get_phoneNumber_user() const
{
    std::vector<std::string> result;
    for (const auto &item : _user.get_Item())
    {
        result.push_back(item->get_phoneNumber());
    }
    return result;
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

bool UserManagement::containsKeyword(const std::string &keyword, const int &option, const User &us) const
{
    std::regex pattern("^" + keyword + "$", std::regex_constants::icase); // không phân biệt hoa thường
    switch (option)
    {
    case 1:
        return std::regex_match(us.get_id(), pattern);
    case 2:
        return std::regex_match(us.get_username(), pattern);
    case 3:
        return std::regex_match(us.get_name(), pattern);
    default:
        return false;
    }
}

std::vector<std::string> UserManagement::search(const std::string &keyword, const int &optionSearch)
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
