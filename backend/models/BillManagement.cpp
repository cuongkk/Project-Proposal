#include "BillManagement.h"

void BillManagement::add(std::shared_ptr<Bill> sp)
{
    set_id_counter(sp->get_id(), _id_counter_bill);
    _bill.add_Tail(sp);
}

void BillManagement::remove(std::shared_ptr<Bill> sp)
{
    delete_id_counter(sp->get_id(), _id_counter_bill);
    _bill.remove_from_KhoHang(sp);
}

std::shared_ptr<Bill> BillManagement::getBill_from_id(const std::string &id)
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

std::list<std::shared_ptr<Bill>> BillManagement::getBill_from_id_Customer(const std::string &id)
{
    std::list<std::shared_ptr<Bill>> result;
    for (const auto &item : _bill.get_Item())
    {
        if (item->get_id_Customer() == id)
        {
            result.push_back(item->clone());
        }
    }
    return result;
}

// bool BillManagement::containsKeyword(const std::string &keyword, const int &option, const Bill &bill) const
// {
//     std::regex pattern("^" + keyword + "$", std::regex_constants::icase); // không phân biệt hoa thường
//     switch (option)
//     {
//     case 1: // Tìm kiếm theo mã bill
//         return std::regex_match(bill.get_id(), pattern);
//     case 2: // Tìm kiếm theo mã khách hàng
//         return std::regex_match(bill.get_id_Customer(), pattern);
//     case 3: // Tìm kiếm theo tổng tiền
//         return std::regex_match(bill.get_totalCost(), pattern);
//     default:
//         return false; // Invalid option
//     }
// }

// std::vector<std::string> BillManagement::search(const std::string &keyword, const int &optionSearch)
// {
//     bool found = false;
//     std::vector<std::string> result;
//     for (const auto &bill : _bill.get_Item())
//     {
//         if (containsKeyword(keyword, optionSearch, *bill))
//         {
//             found = true;
//             result.push_back(bill->get_id());
//         }
//     }
//     if (!found)
//     {
//         std::cout << "Không tìm thấy hóa đơn nào.\n";
//     }
//     return result;
// }

void BillManagement::clear()
{
    _bill.clear();
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