
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
    static std::vector<int> _id_counter_bill;

    BillManagement() = default;
    ~BillManagement() = default;

    void add(std::shared_ptr<Bill>);
    void remove(std::shared_ptr<Bill>);
    std::shared_ptr<Bill> getBill_from_id(const std::string &);
    std::list<std::shared_ptr<Bill>> getBill_from_id_Customer(const std::string &);
    // bool containsKeyword(const std::string &, const int &, const Bill &) const;
    // std::vector<std::string> search(const std::string &, const int &);
    std::shared_ptr<Bill> confirmBill(UserManagement &, const std::string &, Cart &&);
    void clear();

    friend std::ostream &operator<<(std::ostream &, const BillManagement &);
    friend bool operator==(const Bill &, const Bill &);
};
#endif