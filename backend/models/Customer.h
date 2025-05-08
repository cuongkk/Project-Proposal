#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Main.h"
#include "Money.h"
#include "User.h"

class Customer : public User
{
protected:
    std::string _fullname;
    std::string _email;
    std::string _phoneNumber;
    Money _money;

public:
    Customer();
    ~Customer();
    Customer(const std::string &, const std::string &, const std::string &);
    Customer(const std::string &, const std::string &, const std::string &,
             const std::string &, const std::string &, const std::string &,
             const std::string &);

    void set_fullname(const std::string &) override;
    std::string get_fullname() const override;
    void set_email(const std::string &) override;
    std::string get_email() const override;
    void set_phoneNumber(const std::string &) override;
    std::string get_phoneNumber() const override;
    void set_money(const std::string &) override;
    std::string get_money() const override;

    std::unique_ptr<User> clone() const override;
    User *get_origin() const override;

    void print(std::ostream &) const override;
};
#endif