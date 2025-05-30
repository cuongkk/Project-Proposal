#ifndef USER_H
#define USER_H

#include "Main.h"
#include "Cart.h"

class User
{
protected:
    std::string _id_user;
    std::string _username;
    std::string _password;
    std::string _name;
    std::string _imagePath;
    User *_origin = nullptr;

public:
    Cart _cart;

    User();
    virtual ~User() = default;
    User(const std::string &, const std::string &,
         const std::string &, const std::string &,
         const std::string &);

    virtual std::shared_ptr<User> clone() const = 0;
    virtual User *get_origin() const = 0;

    std::string get_id() const;
    void set_username(const std::string &);
    std::string get_username() const;
    void set_password(const std::string &);
    std::string get_password() const;
    void set_name(const std::string &);
    std::string get_name() const;
    void set_imagePath(const std::string &);
    std::string get_imagePath() const;

    virtual void set_fullname(const std::string &) = 0;
    virtual std::string get_fullname() const = 0;
    virtual void set_email(const std::string &) = 0;
    virtual std::string get_email() const = 0;
    virtual void set_phoneNumber(const std::string &) = 0;
    virtual std::string get_phoneNumber() const = 0;
    virtual void set_money(const std::string &) = 0;
    virtual std::string get_money() const = 0;
    virtual Cart get_cart() const = 0;

    friend std::string operator-(const std::shared_ptr<User> &, const std::string &);

    friend bool operator<=(const std::shared_ptr<User> &, const long long &);
    friend bool operator>=(const std::shared_ptr<User> &, const long long &);
    friend bool operator==(const User &, const User &);

    virtual void print(std::ostream &) const = 0;
    friend std::ostream &operator<<(std::ostream &, const User &);
};

#endif