#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "User.h"
#include <iostream>
#include <string>

class Customer : public User
{
protected:
    std::string _name;
    std::string _email;
    std::string _phoneNumber;
    std::string _money;

public:
    Customer();
    ~Customer();
    Customer(const std::string &, const std::string &, const std::string &, const std::string &,
             const std::string &, const std::string &, const std::string &);

    std::unique_ptr<User> clone() const override;
    User *get_origin() const override;

    void print(std::ostream &) const override;
};
#endif