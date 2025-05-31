#include "Main_all.h"
#include "Main.h"

std::vector<int> UserManagement::_id_counter_user = {0};

std::vector<int> BillManagement::_id_counter_bill = {0};

std::vector<int> KhoHang::_id_counter_sp = {0};

std::string create_id(const std::string &prefix, const int &counter)
{
    std::string id_str = std::to_string(counter);
    while (id_str.size() < 4)
    {
        id_str = '0' + id_str;
    }
    return std::string(prefix) + id_str;
}

int get_counter_from_id(const std::string &prefix, const std::string &id)
{
    std::string counter = id.substr(prefix.size());
    return std::stoi(counter);
}

void set_id_counter(const std::string &id, std::vector<int> &_id_counter)
{
    int counter = get_counter_from_id("AA", id);
    if (counter >= _id_counter.size())
    {
        for (int i = _id_counter.size(); i < counter; i++)
        {
            _id_counter.push_back(0);
        }
        _id_counter[counter - 1] = 1;
    }
}
void delete_id_counter(const std::string &id, std::vector<int> &_id_counter)
{
    int counter = get_counter_from_id("AA", id);
    if (counter < _id_counter.size())
    {
        _id_counter[counter - 1] = 0;
    }
}
std::string set_id(const std::string &prefix, std::vector<int> &_id_counter)
{
    std::string id = "";
    for (int i = 0; i < _id_counter.size(); i++)
    {
        if (_id_counter[i] == 0)
        {
            id = create_id(prefix, i + 1);
            _id_counter[i] = 1;
            return id;
        }
        else if (_id_counter[i] == 1 && i < _id_counter.size() - 1)
        {
            continue;
        }
        else if (_id_counter[_id_counter.size() - 1] == 1)
        {
            _id_counter.push_back(1);
            id = create_id(prefix, _id_counter.size());
            _id_counter[i] = 1;
            return id;
        }
    }
    return id;
}

bool findContains(const std::string &text, const std::string &pattern)
{
    std::regex regex(pattern, std::regex_constants::icase);
    return std::regex_search(text, regex);
}

bool is_positive_number(const std::string &str)
{
    if (str.empty())
        return false;
    for (char c : str)
    {
        if (!isdigit(c))
            return false;
    }
    return !str.empty() && std::stoll(str) >= 0;
}

bool is_diffrent_name(const std::string &name, const std::vector<std::string> &names)
{
    for (int i = 0; i < names.size(); i++)
    {
        std::string existing_name = names[i];
        if (name == existing_name)
        {
            return false;
        }
    }
    return true;
}

void runAllTests()
{
    // Test 1: Thêm sản phẩm vào giỏ hàng
    {
        Drink d("SP0001", "Coca", "Nước ngọt", 1, "10000", "0",
                DateTime("2024-01-01"), DateTime("2025-01-01"), "coca.jpg");
        Cart cart;
        bool added = cart.add(std::make_unique<Drink>(d));
        assert(added == true);
        assert(cart.get_size() == 1);
        assert(cart.get_money() == "10000");
    }

    // Test 2: Clone hóa đơn
    {
        Cart cart("US0001", LinkedList<Product>());
        DateTime dt("2024-05-31");
        Bill bill("HD001", "US001", std::move(cart), dt);
        auto copy = bill.clone();
        assert(copy->get_id() == "HD001");
        assert(copy->get_id_Customer() == "US001");
    }

    // Test 3: Gán và lấy thông tin người dùng
    {
        Customer cus("US0001", "khai123", "123456", "Khai", "img.jpg");
        cus.set_email("khai@example.com");
        cus.set_phoneNumber("0123456789");
        cus.set_money("20000");
        assert(cus.get_email() == "khai@example.com");
        assert(cus.get_phoneNumber() == "0123456789");
        assert(cus.get_money() == "20000");
    }

    // Test 4: DateTime parsing
    {
        DateTime dt("2025-06-01");
        assert(dt.get_year() == 2025);
        assert(dt.get_month() == 6);
        assert(dt.get_day() == 1);
    }

    // Test 5: Test Cart
    Food food("SP0002", "Coca", "Nước ngọt", 1, "10000", "0",
              DateTime("2024-01-01"), DateTime("2025-01-01"), "coca.jpg");
    assert(food.get_id() == "F001");
    assert(food.get_price().get_value() == 20000);

    Drink drink("SP0003", "Coca", "Nước ngọt", 1, "10000", "0",
                DateTime("2024-01-01"), DateTime("2025-01-01"), "coca.jpg");
    assert(drink.get_name() == "Coca");

    Cart cart;
    cart.add(food.clone());
    cart.add(drink.clone());
    assert(cart.get_list().size() == 2);
    assert(cart.get_money().get_value() == 30000);

    std::cout << " PASSED.\n";
}