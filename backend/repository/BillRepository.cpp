#include "BillRepository.h"

BillRepositoryImpl::BillRepositoryImpl(const std::string &host,
                                       const std::string &user,
                                       const std::string &pass,
                                       const std::string &db)
{
    driver = sql::mysql::get_mysql_driver_instance();
    conn.reset(driver->connect(host, user, pass));
    conn->setSchema(db);
    conn->setClientOption("CHARSET", "utf8mb4");
}

void BillRepositoryImpl::set_bills(const std::shared_ptr<sql::ResultSet> &res)
{
}

void BillRepositoryImpl::loadFromDatabase()
{
}

const LinkedList<Bill> &BillRepositoryImpl::getAll()
{
    return _bills;
}

void BillRepositoryImpl::insert(const std::vector<std::string> &fields, const LinkedList<Product> &products)
{
    if (fields.size() != 4)
    {
        throw std::invalid_argument("Không đủ số lượng trường cho hóa đơn (cần 4).");
    }

    std::shared_ptr<sql::PreparedStatement> pstmt(conn->prepareStatement(
        "INSERT INTO Bill (id_Bill, id_User, totalCost, paid_date) "
        "VALUES (?, ?, ?, ?)"));

    pstmt->setString(1, fields[0]);
    pstmt->setString(2, fields[1]);
    pstmt->setInt(3, std::stoll(fields[2]));
    pstmt->setString(4, fields[3]);
    pstmt->executeUpdate();

    pstmt = std::shared_ptr<sql::PreparedStatement>(
        conn->prepareStatement(
            "INSERT INTO Bill_Details (id_Bill, id_Product, quantity, price) VALUES (?, ?, ?, ?)"));

    for (const auto &product : products)
    {
        pstmt->setString(1, fields[0]);
        pstmt->setString(2, product->get_id());
        pstmt->setInt(3, product->get_quantity());
        pstmt->setInt(4, std::stoll(product->get_money()) * (100 - std::stoll(product->get_discount())) / 100);
        pstmt->executeUpdate();
    }
}
