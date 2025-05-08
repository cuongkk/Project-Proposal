
#ifndef _BILLMANAGEMENT_H
#define _BILLMANAGEMENT_H

#include "Main.h"
#include "Bill.h"
#include "KhoHang.h"
#include "LinkedList.h"

class BillManagement
{
private:
    LinkedList<Bill> _bill;

public:
    BillManagement() = default;
    ~BillManagement() = default;

    void add(std::unique_ptr<Bill>);
    void remove(std::unique_ptr<Bill>);
    std::unique_ptr<Bill> getBill_from_id(const std::string &);
    bool containsKeyword(const std::string &, const int &, const Bill &) const;
    std::vector<std::string> search(const std::string &, const int &);
    std::unique_ptr<Bill> confirmBill(UserManagement &, const std::string &, Cart &&);

    friend std::ostream &operator<<(std::ostream &, const BillManagement &);
    friend bool operator==(const Bill &, const Bill &);
};
#endif