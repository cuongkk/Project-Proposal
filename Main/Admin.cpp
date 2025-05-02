#include "Admin.h"

Admin::Admin() : User()
{
}

Admin::~Admin()
{
}
Admin::Admin(const std::string &username, const std::string &password, const std::string &inf)
    : User(username, password, inf)
{
}

std::unique_ptr<User> Admin::clone() const
{
    auto cloned = std::make_unique<Admin>(*this);
    auto nonconst_this = const_cast<Admin *>(this);
    cloned->_origin = static_cast<User *>(nonconst_this);
    return cloned;
}

User *Admin::get_origin() const
{
    return _origin;
}
void Admin::print(std::ostream &os) const
{
    os << _id_user << ", ";
    os << _username << ", ";
    os << _password << ", ";
    os << _inf;
}
