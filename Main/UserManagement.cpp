#include "UserManagement.h"
#include <iostream>

void UserManagement::add(std::unique_ptr<User> sp)
{
    _user.add_Tail(std::move(sp));
}

void UserManagement::remove(std::unique_ptr<User> sp)
{
    _user.remove_from_KhoHang(std::move(sp));
}

std::unique_ptr<User> UserManagement::getUser_from_id(const std::string &id)
{
    for (const auto &sp : _user.get_SanPham())
    {
        if (sp->get_id() == id)
        {
            return sp->clone();
        }
    }
    return nullptr;
}

std::ostream &operator<<(std::ostream &os, const UserManagement &KhoHang)
{
    os << KhoHang._user;
    return os;
}
