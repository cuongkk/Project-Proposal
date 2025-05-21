#include "Route.h"

int main()
{

    try
    {
        ProductRepositoryImpl repo(
            "tcp://127.0.0.1:3306", "root", "2005", "Canteen_Management");

        repo.loadFromDatabase();

        std::vector<std::string> fields = {
        "SP003",
        "Trà Sữa Trân Châu",
        "Nước",
        "Đồ uống",
        "35000.0",
        "0.1",
        "50",
        "2025-01-01",
        "2026-01-01",
        "trasua.png"
        };
        repo.insertProduct(fields);
        std::cout << "Products loaded from database:\n";


        for (const auto &product : repo.getAll())
        {
            std::cout << *product << "\n";
        }
    }
    catch (const sql::SQLException &e)
    {
        std::cout << "❌ SQL Error: " << e.what() << "\n";
    }
    catch (const std::exception &e)
    {
        std::cout << "❌ General Error: " << e.what() << "\n";
    }
    catch (...)
    {
        std::cout << "❌ Unknown error occurred.\n";
    }

    crow::App<CORS> app;

    setup_user_routes(app);
    setup_signup_routes(app);
    setup_login_routes(app);
    setup_inf_user_routes(app);
    setup_update_inf_user_routes(app);
    setup_add_product_routes(app);
    setup_show_product_routes(app);
    setup_show_image_product_routes(app);
    setup_add_product_to_cart_routes(app);
    setup_remove_product_from_cart_routes(app);
    setup_show_cart_routes(app);
    setup_checkout_routes(app);
    setup_show_bill_routes(app);

    app.port(18080).multithreaded().run();
    return 0;
}