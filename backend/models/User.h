#ifndef USER_H
#define USER_H

#include "Main.h"

class User
{
protected:
    std::string _id_user;
    std::string _username;
    std::string _password;
    std::string _name;
    User *_origin = nullptr;

public:
    static std::vector<int> _id_counter_user;

    User();
    virtual ~User() = default;
    User(const std::string &, const std::string &, const std::string &);

    virtual std::unique_ptr<User> clone() const = 0;
    virtual User *get_origin() const = 0;
    virtual std::string get_money() const = 0;
    virtual void set_money(const std::string &) = 0;

    void set_counter(const int &);
    std::string get_id() const;
    void set_username(const std::string &);
    std::string get_username() const;
    void set_password(const std::string &);
    std::string get_password() const;
    void set_name(const std::string &);
    std::string get_name() const;

    friend std::string operator-(const std::unique_ptr<User> &, const std::string &);

    friend bool operator<=(const std::unique_ptr<User> &, const long long &);
    friend bool operator>=(const std::unique_ptr<User> &, const long long &);
    friend bool operator==(const User &, const User &);

    virtual void print(std::ostream &) const = 0;
    friend std::ostream &operator<<(std::ostream &, const User &);
};

#endif