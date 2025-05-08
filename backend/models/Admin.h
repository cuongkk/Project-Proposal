
#ifndef ADMIN_H
#define ADMIN_H

#include "Main.h"
#include "User.h"

class Admin : public User
{
public:
    Admin();
    ~Admin();
    Admin(const std::string &, const std::string &, const std::string &);

    std::unique_ptr<User> clone() const override;
    User *get_origin() const override;

    void set_fullname(const std::string &) override {};
    std::string get_fullname() const override { return ""; };
    void set_email(const std::string &) override {};
    std::string get_email() const override { return ""; };
    void set_phoneNumber(const std::string &) override {};
    std::string get_phoneNumber() const override { return ""; };
    void set_money(const std::string &) override {};
    std::string get_money() const override { return ""; };

    void print(std::ostream &) const override;
};
#endif