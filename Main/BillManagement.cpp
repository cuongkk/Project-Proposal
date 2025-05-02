#include "BillManagement.h"

void BillManagement::add(std::unique_ptr<Bill> sp)
{
    _bill.add_Tail(std::move(sp));
}

void BillManagement::remove(std::unique_ptr<Bill> sp)
{
    _bill.remove_from_KhoHang(std::move(sp));
}

std::unique_ptr<Bill> BillManagement::getBill_from_id(const std::string &id)
{
    for (const auto &item : _bill.get_Item())
    {
        if (item->get_id() == id)
        {
            return item->clone();
        }
    }
    return nullptr;
}

std::ostream &operator<<(std::ostream &os, const BillManagement &billManagement)
{
    os << billManagement._bill;
    return os;
}

bool operator==(const Bill &a, const Bill &b)
{
    return a.get_id() == b.get_id();
}