#include "Route.h"

UserManagement userManagement;

std::vector<std::string> username = {"user1", "user2"};
std::unordered_map<std::string, std::string> UserList = {};
std::unordered_map<std::string, std::string> workUser = {};
// void add_cors_headers(crow::response &res)
// {
//     res.add_header("Access-Control-Allow-Origin", "*");
//     res.add_header("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
//     res.add_header("Access-Control-Allow-Headers", "Content-Type");
// }

void setup_user_routes(crow::App<CORS> &app)
{
    app.route_dynamic("/api/<string>")
        .methods("OPTIONS"_method)([](const crow::request &, std::string)
                                   {
            crow::response res;
            // add_cors_headers(res);
            res.code = 204; 
            return res; });

    CROW_ROUTE(app, "/api/<string>").methods("GET"_method)([](const crow::request &, std::string username)
                                                           {
            crow::json::wvalue res;
            crow::response response;

            // add_cors_headers(response);

            if (!UserList.count(username)) {
                res["error"] = "User not found";
                response.code = 404;
                response.write(res.dump());
                return response;
            }

            std::stringstream ss(UserList[username]);
            std::string func;
            int i = 0;
            while (std::getline(ss, func, '|')) {
                res["functions"][i++] = func;
            }

            response.write(res.dump());
            return response; });
}

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
    CROW_ROUTE(app, "/signup").methods(crow::HTTPMethod::POST)([](const crow::request &req)
                                                               {
        auto body = crow::json::load(req.body);
        if (!body)
            return crow::response(400, "Invalid JSON");

        std::string username = body["username"].s();
        std::string password = body["password"].s();
        std::string name = body["name"].s();
        auto User = std::make_unique<Customer>("", "" ,"");
        crow::json::wvalue result;

        if(!userManagement.check_username(username))
        {
            result["message"] = username + " đã trùng lặp, ";
        }
        else if(!userManagement.check_name(name))
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