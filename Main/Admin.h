#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"

class Admin : public User
{
public:
    Admin();
    ~Admin();
    Admin(const std::string &, const std::string &, const std::string &);

    std::unique_ptr<User> clone() const override;
    User *get_origin() const override;

    void print(std::ostream &) const override;
};
#endif