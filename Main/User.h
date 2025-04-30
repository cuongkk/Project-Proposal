#ifndef USER_H
#define USER_H

#include "Utils.h"
#include <vector>
#include <string>
#include <iostream>
#include <memory>

class User
{
protected:
    std::string _id;
    std::string _username;
    std::string _password;
    std::string _inf;
    static std::vector<int> _id_counter_user;
    User *_origin = nullptr;

public:
    User();
    virtual ~User() = default;
    User(const std::string &, const std::string &, const std::string &);
    virtual std::unique_ptr<User> clone() const = 0;
    virtual User *get_origin() const = 0;

    void set_counter(const int &);
    std::string get_id() const;
    void set_username(const std::string &);
    std::string get_username() const;
    void set_password(const std::string &);
    std::string get_password() const;
    void set_inf(const std::string &);
    std::string get_inf() const;

    friend bool operator==(const User &, const User &);

    virtual void print(std::ostream &) const = 0;
    friend std::ostream &operator<<(std::ostream &, const User &);
};

#endif