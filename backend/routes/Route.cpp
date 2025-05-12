#include "Route.h"

// int main()
// {
//     return 0;
// }

UserManagement userManagement;
KhoHang khoHang;

std::vector<std::string> username = {"user1", "user2"};
std::unordered_map<std::string, std::string> UserList = {};
std::unordered_map<std::string, std::string> workUser = {};
// void add_cors_headers(crow::response &res)
// {
//     res.add_header("Access-Control-Allow-Origin", "*");
//     res.add_header("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
//     res.add_header("Access-Control-Allow-Headers", "Content-Type");
// }

void setup_username_routes(crow::App<CORS> &app)
{
    CROW_ROUTE(app, "/api/username").methods("GET"_method)([](const crow::request &)
                                                           {
                crow::json::wvalue res;
                crow::response response;
            
                // add_cors_headers(response);
                            
                for (size_t i = 0; i < username.size(); ++i) {
                    res[i] = username[i];
                }
            
                response.write(res.dump());
                return response; });

    app.route_dynamic("/api/username")
        .methods("OPTIONS"_method)([](const crow::request &)
                                   {
                crow::response res;
                // add_cors_headers(res);
                res.code = 204; 
                return res; });
}

void setup_signup_routes(crow::App<CORS> &app)
{
    auto admin = std::make_unique<Admin>("admin", "admin", "admin");
    userManagement.add(std::move(admin));
    CROW_ROUTE(app, "/signup").methods(crow::HTTPMethod::POST)([](const crow::request &req)
                                                               {
        auto body = crow::json::load(req.body);
        if (!body)
            return crow::response(400, "Invalid JSON");

        std::string username = body["username"].s();
        std::string password = body["password"].s();
        std::string name = body["name"].s();
        auto User = std::make_unique<Customer>();
        crow::json::wvalue result;

        if(!is_diffrent_name(username, userManagement.get_username_user()))
        {
            result["message"] = username + " đã trùng lặp, ";
        }
        else if(!is_diffrent_name(name, userManagement.get_name_user()))
        {
            result["message"] = name + " đã trùng lặp";
        }
        else
        {
            User = std::make_unique<Customer>(username, password, name);
            userManagement.add(std::move(User));
            result["message"] = "Thành công";
        }

        return crow::response{result.dump()}; });
}

void setup_login_routes(crow::App<CORS> &app)
{
    CROW_ROUTE(app, "/login").methods(crow::HTTPMethod::POST)([](const crow::request &req)
                                                              {
        auto body = crow::json::load(req.body);
        if (!body)
            return crow::response(400, "Invalid JSON");

        std::string username = body["username"].s();
        std::string password = body["password"].s();
        auto User = std::make_unique<Customer>();
        crow::json::wvalue result;

        std::vector<std::string> id_user = userManagement.search(username, 2);

        if (id_user.size() == 0)
        {
            result["message"] = username + " Không tồn tại ";
            return crow::response{result.dump()};
        }

        std::string true_password = userManagement.getUser_from_id(id_user[0])->get_password();
       
        if (password == "")
        {
            result["message"] = "Vui lòng nhập mật khẩu";
            return crow::response{result.dump()};
        }
        else if(password != true_password)
        {
            result["message"] = "Sai mật khẩu";
            return crow::response{result.dump()};
        }
        else
        {
            result["id_user"] = id_user[0];
        }

        return crow::response{result.dump()}; });
}

void setup_user_routes(crow::App<CORS> &app)
{
    CROW_ROUTE(app, "/user").methods(crow::HTTPMethod::POST)([](const crow::request &req)
                                                             {
        auto body = crow::json::load(req.body);
        if (!body || !body.has("id_user"))
            return crow::response(400, "Invalid request: missing 'msg'");
    
        std::string _id_user = body["id_user"].s();

        auto userPtr = userManagement.getUser_from_id(_id_user);
        if (!userPtr)
            return crow::response(404, "User not found");
                    
        crow::json::wvalue res;
        res["name"] = userPtr->get_name();
    
        return crow::response{res}; });
}

void setup_inf_user_routes(crow::App<CORS> &app)
{
    CROW_ROUTE(app, "/inf_user").methods(crow::HTTPMethod::POST)([](const crow::request &req)
                                                                 {
        auto body = crow::json::load(req.body);
        if (!body || !body.has("id_user"))
            return crow::response(400, "Invalid request: missing 'msg'");

        crow::json::wvalue res;

        std::string id_user = body["id_user"].s();

        auto userPtr = userManagement.getUser_from_id(id_user);
        if (!userPtr)
            return crow::response(404, "User not found");

        std::string _username = userPtr->get_username();
        std::string _password = userPtr->get_password();
        std::string _name = userPtr->get_name();
        std::string _fullname = userPtr->get_fullname();
        std::string _email = userPtr->get_email();
        std::string _phoneNumber = userPtr->get_phoneNumber();
        std::string _money = userPtr->get_money();

        res["username"] = _username;
        res["password"] = _password;
        res["name"] = _name;
        res["fullname"] = _fullname;
        res["email"] = _email;
        res["phoneNumber"] = _phoneNumber;
        res["money"] = _money;
        res["message"] = "Thành công";
        return crow::response{res}; });
}

void setup_update_inf_user_routes(crow::App<CORS> &app)
{
    CROW_ROUTE(app, "/update_inf_user").methods(crow::HTTPMethod::POST)([](const crow::request &req)
                                                                        {
                            auto body = crow::json::load(req.body);
        if (!body || !body.has("id_user"))
            return crow::response(400, "Invalid request: missing 'msg'");

        crow::json::wvalue res;

        std::string id_user = body["id_user"].s();

        auto userPtr = userManagement.getUser_from_id(id_user);
        if (!userPtr)
            return crow::response(404, "User not found");

        std::string _fullname = body["fullname"].s();
        std::string _email = body["email"].s();
        std::string _phoneNumber = body["phoneNumber"].s();
        std::string _money = body["money"].s();

        if (_fullname == "")
        {
            res["message"] = "Vui lòng nhập họ tên";
            return crow::response{res};
        }
        else if (_fullname.length() > 50)
        {
            res["message"] = "Họ tên không được quá 50 ký tự";
            return crow::response{res};
        }
        else if (_email == "")
        {
            res["message"] = "Vui lòng nhập email";
            return crow::response{res};
        }
        else if (is_diffrent_name(_email, userManagement.get_email_user()))
        {
            res["message"] = _email + " đã trùng lặp";
            return crow::response{res};
        }
        else if (_phoneNumber == "")
        {
            res["message"] = "Vui lòng nhập số điện thoại";
            return crow::response{res};
        }
        else if (is_diffrent_name(_phoneNumber, userManagement.get_phoneNumber_user()))
        {
            res["message"] = _phoneNumber + " đã trùng lặp";
            return crow::response{res};
        }
        else if (_phoneNumber.length() != 10)
        {
            res["message"] = "Số điện thoại không hợp lệ";
            return crow::response{res};
        }
        else if (_money == "")
        {
            res["message"] = "Vui lòng nhập số tiền";
            return crow::response{res};
        }
        else if (!is_positive_number(_money))
        {
            res["message"] = "Số tiền không hợp lệ";
            return crow::response{res};
        }
        else
        {
            userPtr->get_origin()->set_fullname(_fullname);
            userPtr->get_origin()->set_email(_email);
            userPtr->get_origin()->set_phoneNumber(_phoneNumber);
            userPtr->get_origin()->set_money(_money);
            res["message"] = "Cập nhật thông tin thành công";
            return crow::response{res};
        }
        res["message"] = "Cập nhật thông tin không thành công";
        return crow::response{res}; });
}

void setup_add_product_routes(crow::App<CORS> &app)
{
    CROW_ROUTE(app, "/add_product").methods(crow::HTTPMethod::POST)([](const crow::request &req)
                                                                    {
    auto body = crow::json::load(req.body);
    if (!body || !body.has("name"))
        return crow::response(400, "Invalid request: missing 'msg'");

    crow::json::wvalue res;

    std::string _name = body["name"].s();
    std::string _inf = body["inf"].s();
    std::string _quantity = body["quantity"].s();
    std::string _price = body["price"].s();
    std::string _discount = body["discount"].s();
    std::string _manufacture_Date = body["manufacture_Date"].s();
    std::string _expiry_Date = body["expiry_Date"].s();

    if (_name == "")
    {
        res["message"] = "Vui lòng nhập tên sản phẩm";
        return crow::response{res};
    }
    else if (_name.length() > 50)
    {
        res["message"] = "Tên sản phẩm không được quá 50 ký tự";
        return crow::response{res};
    }
    else if (is_diffrent_name(_name, khoHang.get_name_product()))
    {
        res["message"] = _name + " đã trùng lặp";
        return crow::response{res};
    }
    else if (_inf.length() > 50)
    {
        res["message"] = "Thông tin sản phẩm không được quá 50 ký tự";
        return crow::response{res};
    }
    else if (_inf == "")
    {
        res["message"] = "Vui lòng nhập thông tin sản phẩm";
        return crow::response{res};
    }
    else if (!(findContains(_inf, "thức ăn") != std::string::npos || findContains(_inf, "đồ uống") != std::string::npos))
    {
        res["message"] = "Thông tin sản phẩm không hợp lệ";
        return crow::response{res};
    }
    else if (_quantity == "")
    {
        res["message"] = "Vui lòng nhập số lượng";
        return crow::response{res};
    }
    else if (!is_positive_number(_quantity))
    {
        res["message"] = "Số lượng không hợp lệ";
        return crow::response{res};
    }
    else if (_price == "")
    {
        res["message"] = "Vui lòng nhập giá tiền";
        return crow::response{res};
    }
    else if (!is_positive_number(_price))
    {
        res["message"] = "Giá tiền không hợp lệ";
        return crow::response{res};
    }

    else if (std::stof(_discount) < 0 || std::stof(_discount) > 100 || !is_positive_number(_discount))
    {
        res["message"] = "Phần trăm giảm giá không hợp lệ";
        return crow::response{res};
    }
    else if (_manufacture_Date == "")
    {
        res["message"] = "Vui lòng nhập ngày sản xuất";
        return crow::response{res};
    }
    else if (_expiry_Date == "")
    {
        res["message"] = "Vui lòng nhập ngày hết hạn";
        return crow::response{res};
    }

    int year_manufacture_Date = std::stoi(_manufacture_Date.substr(0, 4));
    int month_manufacture_Date = std::stoi(_manufacture_Date.substr(5, 2));
    int day_manufacture_Date = std::stoi(_manufacture_Date.substr(8, 2));

    int year_expiry_Date = std::stoi(_expiry_Date.substr(0, 4));
    int month_expiry_Date = std::stoi(_expiry_Date.substr(5, 2));
    int day_expiry_Date = std::stoi(_expiry_Date.substr(8, 2));

    DateTime manufacture_Date(year_manufacture_Date, month_manufacture_Date, day_manufacture_Date);
    DateTime expiry_Date(year_expiry_Date, month_expiry_Date, day_expiry_Date);

    if (manufacture_Date > expiry_Date)
    {
        res["message"] = "Ngày sản xuất không được lớn hơn ngày hết hạn";
        return crow::response{res};
    }

    if (findContains(_inf, "thức ăn"))
    {
        auto food = std::make_unique<Food>(_name, _inf, std::stoi(_quantity), _price, std::stof(_discount), std::move(manufacture_Date), std::move(expiry_Date));
        khoHang.add(std::move(food));
        res["message"] = "Thêm sản phẩm thành công";
        return crow::response{res};
    }
    else if (findContains(_inf, "đồ uống"))
    {
        auto drink = std::make_unique<Drink>(_name, _inf, std::stoi(_quantity), _price, std::stof(_discount), std::move(manufacture_Date), std::move(expiry_Date));
        khoHang.add(std::move(drink));
        res["message"] = "Thêm sản phẩm thành công";
        return crow::response{res};
    }
    
    return crow::response{res}; });
}

void setup_show_product_routes(crow::App<CORS> &app)
{
    CROW_ROUTE(app, "/show_product").methods(crow::HTTPMethod::POST)([](const crow::request &req)
                                                                     {
        auto body = crow::json::load(req.body);
        if (!body || !body.has("id_user"))
            return crow::response(400, "Invalid request: missing 'msg'");

        std::string id_user = body["id_user"].s();
        auto userPtr = userManagement.getUser_from_id(id_user);
        if (!userPtr)
            return crow::response(404, "User not found");

        crow::json::wvalue res;
        int i = 0;

        auto BanhMi = std::make_unique<Food>("Bánh mì", "Thức ăn", 10, "20000", 0, DateTime(2023, 10, 1), DateTime(2024, 10, 1));
        khoHang.add(std::move(BanhMi));
        if (khoHang.getProduct().get_size() == 0)
        {
            res["message"] = "Kho hàng trống";
            return crow::response{res};
        }
        else
        {
            const auto &products = khoHang.getProduct(); // lấy tham chiếu tránh copy
            for (auto it = products.begin(); it != products.end(); ++it)
            {
                const auto &product = *it;
                res["products"][i]["name"] = product->get_name();
                res["products"][i]["inf"] = product->get_inf();
                res["products"][i]["quantity"] = product->get_quantity();
                res["products"][i]["price"] = product->get_money();
                res["products"][i]["discount"] = product->get_discount();
                res["products"][i]["manufacture_Date"] = product->get_manufacture_Date().get_date();
                res["products"][i]["expiry_Date"] = product->get_expiry_Date().get_date(); 
                i++;
            }
        }

        return crow::response{res}; });
}

void setup_update_product_routes(crow::App<CORS> &app)
{
    CROW_ROUTE(app, "/update_product").methods(crow::HTTPMethod::POST)([](const crow::request &req)
                                                                       {
        auto body = crow::json::load(req.body);
        if (!body || !body.has("id_user"))
            return crow::response(400, "Invalid request: missing 'msg'");

        std::string _id_user = body["id_user"].s();
        if (_id_user != "US0001")
            return crow::response(404, "User not found");

        crow::json::wvalue res;

        std::string _id_product = body["id_product"].s();
        std::string _update_name = body["update_name"].s();
        std::string _update_inf = body["update_inf"].s();

        if (_update_inf == "")
        {
            res["message"] = "Vui lòng nhập thông tin sản phẩm";
            return crow::response{res};
        }
        else if (_update_name == "quantity")
        {
            if (is_positive_number(_update_inf))
            {
                khoHang.getProduct_from_id(_id_product)->get_origin()->set_quantity(std::stoi(_update_inf));
                res["message"] = "Cập nhật số lượng thành công";
                return crow::response{res};
            }
            else
            {
                res["message"] = "Số lượng không hợp lệ";
                return crow::response{res};
            }
        }
        else if (_update_name == "price")
        {
            if (is_positive_number(_update_inf))
            {
                khoHang.getProduct_from_id(_id_product)->get_origin()->set_money(_update_inf, "VND");
                res["message"] = "Cập nhật giá tiền thành công";
                return crow::response{res};
            }
            else
            {
                res["message"] = "Giá tiền không hợp lệ";
                return crow::response{res};
            }
        }
        else if (_update_name == "discount")
        {
            if (std::stof(_update_inf) < 0 || std::stof(_update_inf) > 100 || !is_positive_number(_update_inf))
            {
                res["message"] = "Phần trăm giảm giá không hợp lệ";
                return crow::response{res};
            }
            else
            {
                khoHang.getProduct_from_id(_id_product)->get_origin()->set_discount(std::stof(_update_inf));
                res["message"] = "Cập nhật phần trăm giảm giá thành công";
                return crow::response{res};
            }
        }

                    return crow::response(404, "User not found"); });
}

void setup_add_product_to_cart_routes(crow::App<CORS> &app)
{
    CROW_ROUTE(app, "/add_product_to_cart").methods(crow::HTTPMethod::POST)([](const crow::request &req)
                                                                            {
        auto body = crow::json::load(req.body);
        if (!body || !body.has("id_user"))
            return crow::response(400, "Invalid request: missing 'msg'");

        std::string id_user = body["id_user"].s();
        auto userPtr = userManagement.getUser_from_id(id_user);
        if (!userPtr)
            return crow::response(404, "User not found");
        
        crow::json::wvalue res;

        std::string _id_product = body["id_product"].s();
        std::string _quantity_change = body["quantity_change"].s();

        if (_quantity_change == "")
        {
            res["message"] = "Vui lòng nhập số lượng";
            return crow::response{res};
        }
        else if (!is_positive_number(_quantity_change))
        {
            res["message"] = "Số lượng không hợp lệ";
            return crow::response{res};
        }
        else
        {
            int quantity = khoHang.getProduct_from_id(_id_product)->get_origin()->get_quantity();
            if (quantity != 0)
            {
                userPtr->_cart.add(khoHang.getProduct_from_id(_id_product)->clone());
                khoHang.getProduct_from_id(_id_product)->get_origin()->set_quantity(quantity - std::stoi(_quantity_change));
                res["message"] = "Success";
                return crow::response{res};
            }
            else
            {
                res["message"] = "Sản phẩm đã hết hàng";
                return crow::response{res};
            }
            
        }

        return crow::response(404, "User not found"); });
}

void setup_show_cart_routes(crow::App<CORS> &app)
{
    CROW_ROUTE(app, "/show_cart").methods(crow::HTTPMethod::POST)([](const crow::request &req)
                                                                  {
        auto body = crow::json::load(req.body);
        if (!body || !body.has("id_user"))
            return crow::response(400, "Invalid request: missing 'msg'");

        std::string id_user = body["id_user"].s();
        auto userPtr = userManagement.getUser_from_id(id_user);
        if (!userPtr)
            return crow::response(404, "User not found");

        crow::json::wvalue res;
        int i = 0;

        if (userPtr->_cart.get_size() == 0)
        {
            res["message"] = "Giỏ hàng trống";
            return crow::response{res};
        }
        else
        {
            const auto &products = userPtr->_cart.get_list();
            for (auto it = products.begin(); it != products.end(); ++it)
            {
                const auto &product = *it;
                res["products"][i]["name"] = product->get_name();
                res["products"][i]["quantity"] = product->get_quantity();
                res["products"][i]["price"] = product->get_money();
                i++;
            }
        }

        return crow::response{res}; });
}