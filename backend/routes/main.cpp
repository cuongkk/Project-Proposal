#include "Route.h"

int main()
{

    crow::App<CORS> app;

    setup_user_routes(app);
    setup_signup_routes(app);
    setup_login_routes(app);
    setup_inf_user_routes(app);
    setup_update_inf_user_routes(app);
    setup_add_product_routes(app);
    setup_show_product_routes(app);
    setup_add_product_to_cart_routes(app);
    setup_remove_product_from_cart_routes(app);
    setup_show_cart_routes(app);
    setup_checkout_routes(app);
    setup_show_bill_routes(app);

    // GET
    CROW_ROUTE(app, "/submit").methods(crow::HTTPMethod::GET)([]()
                                                              {
    crow::json::wvalue result;
    int i = 0;

    for (const auto& pair : UserList)
    {
        result["users"][i]["name"] = pair.first;
        result["users"][i]["email"] = pair.second;
        ++i;
    }

    return crow::response{result.dump()}; });

    // // POST
    // CROW_ROUTE(app, "/submit").methods(crow::HTTPMethod::POST)([](const crow::request &req)
    //                                                            {
    //     auto body = crow::json::load(req.body);
    //     if (!body)
    //         return crow::response(400, "Invalid JSON");

    //     std::string name = body["name"].s();
    //     std::string email = body["email"].s();

    //     UserList.insert(std::make_pair(name, email));

    //     crow::json::wvalue result;
    //     result["message"] = "Received POST from " + name + " with email " + email;

    //     return crow::response{result.dump()}; });

    app.port(18080).multithreaded().run();
    return 0;
}
