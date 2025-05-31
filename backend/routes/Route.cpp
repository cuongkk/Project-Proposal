#include "Route.h"

// int main()
// {
//     return 0;
// }
ProductRepositoryImpl repoProduct("tcp://127.0.0.1:3306", "root", "0328228324", "Canteen_Management");
UserRepositoryImpl repoUser("tcp://127.0.0.1:3306", "root", "0328228324", "Canteen_Management");
BillRepositoryImpl repoBill("tcp://127.0.0.1:3306", "root", "0328228324", "Canteen_Management");

UserManagement userManagement;
KhoHang khoHang;
BillManagement billManagement;

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

void setup_user_routes(crow::App<CORS> &app)
{

    CROW_ROUTE(app, "/user").methods(crow::HTTPMethod::POST)([](const crow::request &req)
                                                             {
        auto body = crow::json::load(req.body);
        if (!body || !body.has("id_user"))
            return crow::response(400, "Invalid request: missing 'msg'");
    
         userManagement.clear();
        repoUser.loadFromDatabase();

        for (const auto &user : repoUser.getAll())
        {
            userManagement.add(user);
        }
        std::string _id_user = body["id_user"].s();

        auto userPtr = userManagement.getUser_from_id(_id_user);
        if (!userPtr)
            return crow::response(404, "User not found");
                    
        crow::json::wvalue res;
        res["name"] = userPtr->get_name();
        res["money"] = userPtr->get_money();
    
        return crow::response{res}; });
}

void setup_signup_routes(crow::App<CORS> &app)
{
    userManagement.clear();
    repoUser.loadFromDatabase();

    for (const auto &user : repoUser.getAll())
    {
        userManagement.add(user);
    }

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

        if (username == "")
        {
            result["message"] = "Vui lòng nhập tên tài khoản";
            return crow::response{result.dump()};
        }
        else if (password == "")
        {
            result["message"] = "Vui lòng nhập mật khẩu";
            return crow::response{result.dump()};
        }
        else if (name == "")
        {
            result["message"] = "Vui lòng nhập họ tên";
            return crow::response{result.dump()};
        }
        else if(!is_diffrent_name(username, userManagement.get_username_user()))
        {
            result["message"] = username + " đã trùng lặp, ";
        }
        else if(!is_diffrent_name(name, userManagement.get_name_user()))
        {
            result["message"] = name + " đã trùng lặp";
        }
        else
        {
            std::cout << "a";
            std::string _id_us = set_id("US", UserManagement::_id_counter_user); 
            repoUser.insert({ _id_us, username, password, name, "../backend/images/user/user.jpg"});
            result["message"] = "Success";
        }

        return crow::response{result.dump()}; });
}

void setup_login_routes(crow::App<CORS> &app)
{
    userManagement.clear();
    repoUser.loadFromDatabase();

    for (const auto &user : repoUser.getAll())
    {
        userManagement.add(user);
    }
    CROW_ROUTE(app, "/login").methods(crow::HTTPMethod::POST)([](const crow::request &req)
                                                              {
        auto body = crow::json::load(req.body);
        if (!body)
            return crow::response(400, "Invalid JSON");

        std::string username = body["username"].s();
        std::string password = body["password"].s();
        crow::json::wvalue result;
        repoUser.filter("", username, "", "", "", "");
        const LinkedList<User> &users = repoUser.getAll();

        if (users.get_size() == 0)
        {
            result["message"] = username + " Không tồn tại ";
            return crow::response{result.dump()};
        }

        std::string true_password = users[0]->get_password();
       
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
        // else
        // {
        //     result["id_user"] = id_user[0];
        // }
        result["message"] = "Thành công";
        result["id_user"] = users[0]->get_id();
        return crow::response{result.dump()}; });
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

        repoUser.filter(id_user, "", "", "", "", "");
        const LinkedList<User> &userPtr = repoUser.getAll();

        std::string _username = userPtr[0]->get_username();
        std::string _password = userPtr[0]->get_password();
        std::string _name = userPtr[0]->get_name();
        std::string _fullname = userPtr[0]->get_fullname();
        std::string _email = userPtr[0]->get_email();
        std::string _phoneNumber = userPtr[0]->get_phoneNumber();
        std::string _money = userPtr[0]->get_money();
        std::string _imagePath = userPtr[0]->get_imagePath();

        res["username"] = _username;
        res["password"] = _password;
        res["name"] = _name;
        res["fullname"] = _fullname;
        res["email"] = _email;
        res["phoneNumber"] = _phoneNumber;
        res["money"] = _money;
        res["imagePath"] = _imagePath;
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

        std::string field = body["field"].s();
        std::string newValue = body["value"].s();
        
        if (field == "fullname")
        {
            if (newValue == "")
            {
                res["message"] = "Vui lòng nhập họ tên";
                return crow::response{res};
            }
            else if (newValue.length() > 50)
            {
                res["message"] = "Họ tên không được quá 50 ký tự";
                return crow::response{res};
            }
            repoUser.update(id_user, newValue, "", "", "", "");
            res["message"] = "Cập nhật họ tên thành công";
            return crow::response{res};

        }
        else if (field == "email")
        {
            if (newValue == "")
            {
                res["message"] = "Vui lòng nhập email";
                return crow::response{res};
            }
            else if (newValue.length() > 50)
            {
                res["message"] = "Email không được quá 50 ký tự";
                return crow::response{res};
            }
            else if (!is_diffrent_name(newValue, userManagement.get_email_user()))
            {
                res["message"] = newValue + " đã trùng lặp";
                return crow::response{res};
            }
            repoUser.update(id_user, "", newValue, "", "", "");
            res["message"] = "Cập nhật email thành công";
            return crow::response{res};
        }
        else if (field == "phoneNumber")
        {
            if (newValue == "")
            {
                res["message"] = "Vui lòng nhập số điện thoại";
                return crow::response{res};
            }
            else if (newValue.length() > 15)
            {
                res["message"] = "Số điện thoại không được quá 15 ký tự";
                return crow::response{res};
            }
            else if (!is_diffrent_name(newValue, userManagement.get_phoneNumber_user()))
            {
                res["message"] = newValue + " đã trùng lặp";
                return crow::response{res};
            }
            repoUser.update(id_user, "", "", newValue, "", "");
            res["message"] = "Cập nhật số điện thoại thành công";
            return crow::response{res};
        }
        else if (field == "money")
        {
            if (newValue == "")
            {
                res["message"] = "Vui lòng nhập số tiền";
                return crow::response{res};
            }
            else if (!is_positive_number(newValue))
            {
                res["message"] = "Số tiền không hợp lệ";
                return crow::response{res};
            }
            repoUser.update(id_user, "", "", "", newValue, "");
            res["message"] = "Cập nhật số tiền thành công";
            return crow::response{res};
        }
        else
        {
            res["message"] = "Trường không hợp lệ";
            return crow::response{res};
        }
        res["message"] = "Cập nhật thông tin không thành công";
        return crow::response{res}; });
}

void setup_update_image_user_routes(crow::App<CORS> &app)
{
    CROW_ROUTE(app, "/update_image_user").methods(crow::HTTPMethod::POST)([](const crow::request &req)
                                                                          {
        crow::json::wvalue res;

        // Kiểm tra Content-Type có boundary không
        std::string contentType = req.get_header_value("Content-Type");
        std::smatch match;
        std::regex boundary_regex("boundary=(.*)");
        if (!std::regex_search(contentType, match, boundary_regex)) {
            res["message"] = "Thiếu boundary trong Content-Type";
            return crow::response(400, res);
        }

        std::string boundary = "--" + match[1].str();
        std::string id_user;
        std::string imageFilePath;
        std::ofstream ofs;
        bool isParsingFile = false, startedWriting = false;

        std::istringstream stream(req.body);
        std::string line;

        while (std::getline(stream, line)) {
            if (!line.empty() && line.back() == '\r') line.pop_back();

            if (line.find(boundary) != std::string::npos) {
                if (ofs.is_open()) ofs.close();
                isParsingFile = false;
                startedWriting = false;
                continue;
            }

            if (line.find("Content-Disposition:") != std::string::npos) {
                if (line.find("name=\"id_user\"") != std::string::npos) {
                    std::getline(stream, line); // skip empty line
                    std::getline(stream, id_user);
                    if (!id_user.empty() && id_user.back() == '\r') id_user.pop_back();
                } else if (line.find("filename=") != std::string::npos) {
                    std::string filename = "user_" + std::to_string(time(nullptr)) + ".jpg";
                    std::string imageFolder = "../backend/images/user/";
                    std::filesystem::create_directories(imageFolder);
                    imageFilePath = imageFolder + filename;
                    ofs.open(imageFilePath, std::ios::binary);
                    isParsingFile = true;
                }
                continue;
            }

            if (isParsingFile && !startedWriting) {
                if (line.empty()) {
                    startedWriting = true;
                }
                continue;
            }

            if (startedWriting && isParsingFile && ofs.is_open()) {
                ofs << line << '\n';
            }
        }

        if (id_user.empty()) {
            res["message"] = "Thiếu id_user";
            return crow::response(400, res);
        }

        if (imageFilePath.empty()) {
            res["message"] = "Không nhận được file ảnh";
            return crow::response(400, res);
        }

        // Cập nhật DB
        repoUser.update(id_user, "", "", "", "", imageFilePath);
        res["message"] = "Success";
        res["newImage"] = std::filesystem::path(imageFilePath).filename().string();
        return crow::response(200, res); });
}

void setup_show_user_routes(crow::App<CORS> &app)
{
    khoHang.clear();
    repoProduct.loadFromDatabase();

    for (const auto &product : repoProduct.getAll())
    {
        khoHang.add(product);
    }
    CROW_ROUTE(app, "/show_user").methods(crow::HTTPMethod::POST)([](const crow::request &req)
                                                                  {
        auto body = crow::json::load(req.body);
        std::string name = body["name"].s();


        crow::json::wvalue res;
        int i = 0;

        repoUser.filter("", "", "", name, "", "");
        const LinkedList<User> &users = repoUser.getAll();
        if (users.get_size() == 0)
        {
            res["message"] = "Không có user nào";
            return crow::response{res};
        }
        for (auto it = users.begin(); it != users.end(); ++it)
        {
            const auto &user = *it;
            if (user->get_id() == "US0001") 
                continue;
            res["id_user"][i] = user->get_id();
            res["username"][i] = user->get_username();
            res["password"][i] = user->get_password();
            res["name"][i] = user->get_name();
            res["imagePath"][i] = user->get_imagePath();
            res["fullname"][i] = user->get_fullname();
            res["email"][i] = user->get_email();
            res["phoneNumber"][i] = user->get_phoneNumber();
            res["money"][i] = user->get_money();
            i++;
        }

        return crow::response{res}; });
}

void setup_add_product_routes(crow::App<CORS> &app)
{
    CROW_ROUTE(app, "/add_product").methods(crow::HTTPMethod::POST)([](const crow::request &req)
                                                                    {
        std::string contentType = req.get_header_value("Content-Type");

        std::smatch match;
        std::regex boundary_regex("boundary=(.*)");
        if (!std::regex_search(contentType, match, boundary_regex)) {
            return crow::response(400, "Missing boundary");
        }
        std::string boundary = "--" + match[1].str();

        // Biến lưu dữ liệu text
        std::string _name, _inf, _type, _quantity, _price, _discount, _manufacture_Date, _expiry_Date;
        std::string imageFilePath;

        std::istringstream stream(req.body);
        std::string line;
        std::string currentField;
        bool isHeader = false;

        std::ostringstream fileContent;
        bool isParsingFile = false;
        bool startedWriting = false;
        std::ofstream ofs;

        // ──────────────── PHẦN 1: ĐỌC DỮ LIỆU TEXT ────────────────
        std::istringstream streamText(req.body);
        while (std::getline(streamText, line)) {
            if (!line.empty() && line.back() == '\r') line.pop_back();

            if (line.find(boundary) != std::string::npos) {
                currentField.clear();
                isHeader = true;
                continue;
            }

            if (isHeader && line.find("Content-Disposition:") != std::string::npos) {
                std::smatch nameMatch;
                std::regex name_regex("name=\"(.*?)\"");
                if (std::regex_search(line, nameMatch, name_regex)) {
                    currentField = nameMatch[1];
                }

                // Bỏ qua phần ảnh (không gán text nếu là ảnh)
                if (line.find("filename=") != std::string::npos) {
                    currentField.clear();
                }

                isHeader = false;
                continue;
            }

            if (!currentField.empty() && !line.empty()) {
                if (currentField == "name") _name = line;
                else if (currentField == "inf") _inf = line;
                else if (currentField == "type") _type = line;
                else if (currentField == "quantity") _quantity = line;
                else if (currentField == "price") _price = line;
                else if (currentField == "discount") _discount = line;
                else if (currentField == "manufacture_Date") _manufacture_Date = line;
                else if (currentField == "expiry_Date") _expiry_Date = line;
            }
        }

        crow::json::wvalue res;

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
    else if (!is_diffrent_name(_name, khoHang.get_name_product()))
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

    DateTime manufacture_Date(day_manufacture_Date, month_manufacture_Date, year_manufacture_Date);
    DateTime expiry_Date(day_expiry_Date, month_expiry_Date, year_expiry_Date);

    if (manufacture_Date > expiry_Date)
    {
        res["message"] = "Ngày sản xuất không được lớn hơn ngày hết hạn";
        return crow::response{res};
    }

        // ──────────────── PHẦN 2: ĐỌC ẢNH (theo bạn gửi) ────────────────
        std::istringstream streamFile(req.body);
        while (std::getline(streamFile, line)) {
            if (!line.empty() && line.back() == '\r') line.pop_back();

            if (line.find(boundary) != std::string::npos) {
                if (ofs.is_open()) {
                    ofs.close();
                }
                isParsingFile = false;
                startedWriting = false;
                continue;
            }

            if (line.find("Content-Disposition:") != std::string::npos && line.find("filename=") != std::string::npos) {
                std::string filename = "product_" + std::to_string(time(nullptr)) + ".jpg";
                std::string imageFolder = "../backend/images/product/";
                std::filesystem::create_directories(imageFolder);
                imageFilePath = imageFolder + filename;
                ofs.open(imageFilePath, std::ios::binary);
                isParsingFile = true;
                continue;
            }

            if (isParsingFile && !startedWriting) {
                if (line.empty()) {
                    startedWriting = true;  
                }
                continue;
            }

            if (startedWriting && isParsingFile && ofs.is_open()) {
                ofs << line << "\n";
            }
        }
    if (imageFilePath.empty())
    {
        res["message"] = "Vui chọn nhập ảnh";
        return crow::response{res};
    }
    else
    {          
        khoHang.clear();
        repoProduct.loadFromDatabase();

        for (const auto& product : repoProduct.getAll())
        {
            khoHang.add(product);
        }  


        std::string _id_sp = set_id("SP", KhoHang::_id_counter_sp); 
        std::vector<std::string> fields = {_id_sp,_name, _inf, _type, _price, _discount, _quantity, manufacture_Date.get_date(), expiry_Date.get_date(), imageFilePath};
        if (_type == "Đồ ăn")
        {
            repoProduct.insert(fields);
            res["message"] = "Thêm sản phẩm thành công";
            return crow::response{res};
        }
        else if (_type == "Đồ uống")
        {
            // auto drink = std::make_unique<Drink>(_id_sp, _name, _inf, std::stoi(_quantity), _price, _discount, std::move(manufacture_Date), std::move(expiry_Date), imageFilePath);
            // khoHang.add(std::move(drink));
            repoProduct.insert(fields);
            res["message"] = "Thêm sản phẩm thành công";
            return crow::response{res};
        }
    }
    res["message"] = "Thêm sản phẩm không thành công";
    return crow::response{res}; });
}

void setup_show_product_routes(crow::App<CORS> &app)
{
    khoHang.clear();
    repoProduct.loadFromDatabase();

    for (const auto &product : repoProduct.getAll())
    {
        khoHang.add(product);
    }
    CROW_ROUTE(app, "/show_product").methods(crow::HTTPMethod::POST)([](const crow::request &req)
                                                                     {
        auto body = crow::json::load(req.body);
        std::string id_user = body["id_user"].s();
        std::string name = body["name"].s();
        std::string category = "";
        if (body["category"].s() == "all")
        {
            category = "";
        }
        else if (body["category"].s() == "Food")
        {
            category = "Đồ ăn";
        }
        else if (body["category"].s() == "Drink")
        {
            category = "Đồ uống";
        }
        std::string priceRange = body["priceRange"].s();
        std::stringstream ss(priceRange);
        std::string min_price, max_price;
        std::getline(ss, min_price, '-');
        std::getline(ss, max_price);
        if (max_price == "0")
        {
            max_price = "1000000000";
        }

        crow::json::wvalue res;
        int i = 0;
        
        repoProduct.filter("", name, category, min_price, max_price);
        const LinkedList<Product> &products = repoProduct.getAll();
        if (products.get_size() == 0)
        {
            res["message"] = "Không có sản phẩm nào";
            return crow::response{res};
        }
        for (auto it = products.begin(); it != products.end(); ++it)
        {
            const auto &product = *it;
            if (product->get_origin()->get_quantity() == 0 && id_user != "US0001")
            {
                continue;
            }
            res["products"][i]["id"] = product->get_id();
            res["products"][i]["name"] = product->get_name();
            res["products"][i]["inf"] = product->get_inf();
            res["products"][i]["quantity"] = product->get_quantity();
            res["products"][i]["price"] = product->get_money();
            res["products"][i]["discount"] = product->get_discount();
            res["products"][i]["manufacture_Date"] = product->get_manufacture_Date().get_date();
            res["products"][i]["expiry_Date"] = product->get_expiry_Date().get_date(); 
            res["products"][i]["image_url"] = product->get_imagePath();
            i++;
        }

        return crow::response{res}; });
}

void setup_show_image_product_routes(crow::App<CORS> &app)
{
    CROW_ROUTE(app, "/images/product/<string>").methods("GET"_method)([](const crow::request &, const std::string &filename)
                                                                      {
        std::string path = "../backend/images/product/" + filename;
        std::ifstream file(path, std::ios::binary);
        if (!file) return crow::response(404);
        std::ostringstream ss;
        ss << file.rdbuf();
        crow::response res(ss.str());
        res.add_header("Content-Type", "image/jpeg");
        return res; });
}

void setup_show_image_user_routes(crow::App<CORS> &app)
{
    CROW_ROUTE(app, "/images/user/<string>").methods("GET"_method)([](const crow::request &, const std::string &filename)
                                                                   {
    std::string path = "../backend/images/user/" + filename;
    std::ifstream file(path, std::ios::binary);
    if (!file) return crow::response(404);
    std::ostringstream ss;
    ss << file.rdbuf();
    crow::response res(ss.str());
    res.add_header("Content-Type", "image/jpeg");
    return res; });
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
        auto userPtr = userManagement.getUser_from_id(id_user)->get_origin();

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
        else if (std::stoi(_quantity_change) > khoHang.getProduct_from_id(_id_product)->get_origin()->get_quantity())
        {
            res["message"] = "Số lượng sản phẩm không đủ";
            return crow::response{res};
        }
        else
        {
            int quantity = std::stoi(_quantity_change);
            std::string money = khoHang.getProduct_from_id(_id_product)->get_origin()->get_money();
            long long discount = std::stoll(khoHang.getProduct_from_id(_id_product)->get_origin()->get_discount());
            std::string cost = std::to_string(std::stoll(money) * (100 - discount) / 100);
            repoBill.updateCart(id_user, _id_product, quantity, cost);
            res["message"] = "Success";
            return crow::response{res};

            
        }
        return crow::response(404, "User not found"); });
}

void setup_remove_product_from_cart_routes(crow::App<CORS> &app)
{
    CROW_ROUTE(app, "/remove_product_from_cart").methods(crow::HTTPMethod::POST)([](const crow::request &req)
                                                                                 {
        auto body = crow::json::load(req.body);
        if (!body || !body.has("id_user"))
            return crow::response(400, "Invalid request: missing 'msg'");

        std::string id_user = body["id_user"].s();
        auto userPtr = userManagement.getUser_from_id(id_user)->get_origin();
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
        else
        {
            int quantity = std::stoi(_quantity_change);
            std::string money = khoHang.getProduct_from_id(_id_product)->get_origin()->get_money();
            long long discount = std::stoll(khoHang.getProduct_from_id(_id_product)->get_origin()->get_discount());
            std::string cost = std::to_string(std::stoll(money) * (100 - discount) / 100);
            repoBill.updateCart(id_user, _id_product, quantity, cost);
            res["message"] = "Success";
            return crow::response{res};
            
            
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
        
        auto userPtr = userManagement.getUser_from_id(id_user)->get_origin();
        if (!userPtr)
            return crow::response(404, "User not found");

        crow::json::wvalue res;
        int i = 0;

        repoBill.filterCart(id_user);
        if (userPtr->_cart.get_size() == 0)
        {
            res["message"] = "Giỏ hàng trống";
            return crow::response{res};
        }
        else
        {
            const auto &list = userPtr->_cart.get_list();
            for (auto &item : list)
            {
                res["products"][i]["id"] = item->get_id();
                res["products"][i]["name"] = item->get_name();
                res["products"][i]["quantity"] = item->get_quantity();
                res["products"][i]["discount"] = item->get_discount();
                res["products"][i]["price"] =  item->get_money();
                res["products"][i]["image_url"] = item->get_imagePath();
                i++;
            }
            res["price"] =  userPtr->_cart.get_money();
            return crow::response{res};
                 
        }
        return crow::response{res}; });
}

void setup_checkout_routes(crow::App<CORS> &app)
{
    CROW_ROUTE(app, "/checkout").methods(crow::HTTPMethod::POST)([](const crow::request &req)
                                                                 {
        auto body = crow::json::load(req.body);
        if (!body || !body.has("id_user"))
            return crow::response(400, "Invalid request: missing 'msg'");

        std::string id_user = body["id_user"].s();
       
        auto userPtr = userManagement.getUser_from_id(id_user)->get_origin();
        if (!userPtr)
            return crow::response(404, "User not found");

        billManagement.clear();
        repoBill.filter("", id_user, "", "");
        const LinkedList<Bill> &bills = repoBill.getAll();
        for (const auto& bill : bills) 
        {
            billManagement.add(bill);
        }

        crow::json::wvalue res;

        if (userPtr->_cart.get_size() == 0)
        {
            res["message"] = "Giỏ hàng trống";
            return crow::response{res};
        }
        else if (std::stoll(userPtr->get_money()) < std::stoll(userPtr->_cart.get_money()))
        {
            res["message"] = "Số tiền không đủ";
            return crow::response{res};
        }
        else
        {
            DateTime dateTime(body["date"]["day"].i(), body["date"]["month"].i(), body["date"]["year"].i());
            std::string _id_bill = set_id("BI", BillManagement::_id_counter_bill);
            repoUser.update(id_user, "", "", "", std::to_string(std::stoll(userPtr->get_money()) - std::stoll(userPtr->get_cart().get_money())), "");
            for (const auto &item : userPtr->_cart.get_list())
            {
                int quantity = khoHang.getProduct_from_id(item->get_id())->get_quantity();
                repoProduct.update(item->get_id(), "", "", "", "", std::to_string(quantity - item->get_quantity()), "", "", "");
            }
            std::vector<std::string> fields = {_id_bill, id_user, userPtr->get_cart().get_money(), dateTime.get_date()};
            repoBill.insert(fields, userPtr->_cart.get_list());
            for (const auto &item : userPtr->_cart.get_list())
            {
                repoBill.deleteCart(id_user, item->get_id());
            }
            res["message"] = "Success";
            return crow::response{res};
        }
        return crow::response{res}; });
}

void setup_show_bill_routes(crow::App<CORS> &app)
{
    CROW_ROUTE(app, "/show_bill").methods(crow::HTTPMethod::POST)([](const crow::request &req)
                                                                  {
        auto body = crow::json::load(req.body);
        if (!body || !body.has("id_user"))
            return crow::response(400, "Invalid request: missing 'msg'");

        std::string id_user = body["id_user"].s();
        auto userPtr = userManagement.getUser_from_id(id_user);
        if (!userPtr)
            return crow::response(404, "User not found");

        crow::json::wvalue res;

        repoBill.filter("", id_user, "", "");
        const LinkedList<Bill> &list = repoBill.getAll();

        if (list.get_size() ==0 ) 
        {
            res["message"] = "Không có hóa đơn nào";
            return crow::response{res};
        }

        int i = 0;
        for (const auto& bill : list) 
        {
            const auto& products = bill->get_cart().get_list();
            int j = 0;

            for (const auto& product : products) 
            {
                auto& p = res["bills"][i]["products"][j];
                p["name"] = product->get_name();
                p["quantity"] = product->get_quantity();
                p["price"] = product->get_money();
                ++j;
            }

            res["bills"][i]["totalCost"] = bill->get_totalCost();
            res["bills"][i]["dateTime"] = bill->get_dateTime().get_date();
            ++i;
        }

        res["message"] = "Success";
        return crow::response{res}; });
}