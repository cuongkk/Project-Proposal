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

void BillRepositoryImpl::filter(const std::string &id, const std::string &id_Customer,
                                const std::string &totalCost, const std::string &paid_date)
{
    _bills.clear();

    if (id.empty() && id_Customer.empty() && totalCost.empty() && paid_date.empty())
    {
        return;
    }

    billQueryBuilder.filterByIdBill(id).filterByIdCustomer(id_Customer).filterByTotalCost(totalCost).filterByPaidDate(paid_date);

    std::shared_ptr<sql::Statement> stmt(conn->createStatement());
    std::shared_ptr<sql::ResultSet> res(
        stmt->executeQuery(billQueryBuilder.buildFilter()));

    while (res->next())
    {
        std::shared_ptr<sql::ResultSet> res1(
            stmt->executeQuery("SELECT id_Product, quantity, price FROM Bill_Details WHERE id_Bill = '" + res->getString("id_Bill") + "'"));
        Cart cart;
        while (res1->next())
        {
            for (int i = 0; i < res1->getInt("quantity"); ++i)
            {
                cart.add(khoHang.getProduct_from_id(res1->getString("id_Product"))->clone());
            }
        }
        auto bill = std::make_shared<Bill>(res->getString("id_Bill"),
                                           res->getString("id_User"),
                                           std::move(cart),
                                           DateTime(res->getString("paid_date")));
        _bills.push_back(bill);
    }
}

void BillRepositoryImpl::filterCart(std::string &id_Customer)
{

    if (id_Customer.empty())
    {
        return;
    }
    userManagement.getUser_from_id(id_Customer)->get_origin()->_cart.clear();

    std::shared_ptr<sql::PreparedStatement> stmt(conn->prepareStatement(
        "SELECT id_Product, quantity, price FROM Cart_Details WHERE id_User = ?"));
    stmt->setString(1, id_Customer);
    std::shared_ptr<sql::ResultSet> res(stmt->executeQuery());

    while (res->next())
    {
        for (int i = 0; i < res->getInt("quantity"); ++i)
        {
            userManagement.getUser_from_id(id_Customer)->get_origin()->_cart.add(khoHang.getProduct_from_id(res->getString("id_Product"))->clone());
            std::cout << "a";
        }
    }
}

void BillRepositoryImpl::updateCart(const std::string &id_Customer, const std::string &id_Product,
                                    const int &quantity, const std::string &price)
{
    if (id_Customer.empty() || id_Product.empty() || price.empty())
    {
        throw std::invalid_argument("Không đủ thông tin để cập nhật giỏ hàng.");
    }

    // Kiểm tra xem bản ghi đã tồn tại chưa
    std::shared_ptr<sql::PreparedStatement> checkStmt(conn->prepareStatement(
        "SELECT COUNT(*) FROM Cart_Details WHERE id_User = ? AND id_Product = ?"));
    checkStmt->setString(1, id_Customer);
    checkStmt->setString(2, id_Product);
    std::shared_ptr<sql::ResultSet> res(checkStmt->executeQuery());

    bool exists = false;
    if (res->next())
    {
        exists = res->getInt(1) > 0;
    }

    if (exists)
    {
        // Nếu đã tồn tại, cập nhật số lượng
        std::shared_ptr<sql::PreparedStatement> updateStmt(conn->prepareStatement(
            "UPDATE Cart_Details SET quantity = quantity + ? WHERE id_User = ? AND id_Product = ?"));
        updateStmt->setInt(1, quantity);
        updateStmt->setString(2, id_Customer);
        updateStmt->setString(3, id_Product);
        updateStmt->executeUpdate();
    }
    else
    {
        // Nếu chưa tồn tại, chèn mới
        std::shared_ptr<sql::PreparedStatement> insertStmt(conn->prepareStatement(
            "INSERT INTO Cart_Details (id_User, id_Product, quantity, price) VALUES (?, ?, ?, ?)"));
        insertStmt->setString(1, id_Customer);
        insertStmt->setString(2, id_Product);
        insertStmt->setInt(3, quantity);
        insertStmt->setInt(4, std::stoll(price));
        insertStmt->executeUpdate();
    }
}

void BillRepositoryImpl::deleteCart(const std::string &id_Customer, const std::string &id_Product)
{
    if (id_Customer.empty() || id_Product.empty())
    {
        throw std::invalid_argument("Không đủ thông tin để xóa sản phẩm khỏi giỏ hàng.");
    }

    std::shared_ptr<sql::PreparedStatement> pstmt(conn->prepareStatement(
        "DELETE FROM Cart_Details WHERE id_User = ? AND id_Product = ?"));
    pstmt->setString(1, id_Customer);
    pstmt->setString(2, id_Product);

    pstmt->executeUpdate();
}