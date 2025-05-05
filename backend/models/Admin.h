#ifndef ADMIN_H
#define ADMIN_H

#include "Main.h"
#include "User.h"
#include "Utils.h"

class Admin : public User
{
public:
    Admin();
    ~Admin();
    Admin(const std::string &, const std::string &, const std::string &);

    std::unique_ptr<User> clone() const override;
    User *get_origin() const override;

    std::string get_money() const override { return ""; };
    void set_money(const std::string &) override {};
    void print(std::ostream &) const override;
};
#endif