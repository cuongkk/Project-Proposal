#ifndef ROUTE_H
#define ROUTE_H

#include "..\models\Main_all.h"
#include "..\repository\UserRepository.h"
#include "..\repository\ProductRepository.h"
#include "..\repository\BillRepository.h"
#include "crow.h"
#include "crow/json.h"
#include <unordered_map>

struct CORS
{
    struct context
    {
    };

    void before_handle(crow::request &req, crow::response &res, context &)
    {
        if (req.method == crow::HTTPMethod::OPTIONS)
        {
            res.code = 204; // No content
            res.end();
        }
    }

    void after_handle(crow::request &, crow::response &res, context &)
    {
        res.add_header("Access-Control-Allow-Origin", "*");
        res.add_header("Access-Control-Allow-Methods", "GET, POST, PUT, DELETE, OPTIONS");
        res.add_header("Access-Control-Allow-Headers", "Content-Type");
    }
};

extern ProductRepositoryImpl repoProduct;
extern UserRepositoryImpl repoUser;
extern BillRepositoryImpl repoBill;

extern std::vector<std::string> username;
extern std::unordered_map<std::string, std::string> UserList;
extern std::unordered_map<std::string, std::string> workUser;

// void add_cors_headers(crow::response &res);
void setup_username_routes(crow::App<CORS> &);

void setup_user_routes(crow::App<CORS> &);

void setup_signup_routes(crow::App<CORS> &);

void setup_login_routes(crow::App<CORS> &);

void setup_inf_user_routes(crow::App<CORS> &);

void setup_update_inf_user_routes(crow::App<CORS> &);

void setup_add_product_routes(crow::App<CORS> &);

void setup_show_product_routes(crow::App<CORS> &);

void setup_show_image_product_routes(crow::App<CORS> &);

void setup_update_product_routes(crow::App<CORS> &);

// void setup_filter_product_routes(crow::App<CORS> &);

void setup_add_product_to_cart_routes(crow::App<CORS> &);

void setup_remove_product_from_cart_routes(crow::App<CORS> &);

void setup_show_cart_routes(crow::App<CORS> &);

void setup_checkout_routes(crow::App<CORS> &);

void setup_show_bill_routes(crow::App<CORS> &);

#endif