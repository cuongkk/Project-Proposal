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

std::ostream &operator<<(std::ostream &os, const UserManagement &userManagement)
{
    os << userManagement._user;
    return os;
}
