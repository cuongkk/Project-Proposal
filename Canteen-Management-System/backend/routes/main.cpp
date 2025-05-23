#include "Route.h"

int main()
{

    // try
    // {
    //     ProductRepositoryImpl repo1("tcp://127.0.0.1:3306", "root", "0328228324", "Canteen_Management");
    //     repo1.loadFromDatabase();

    //     for (auto product : repo1.getAll())
    //     {
    //         khoHang.add(product);
    //     }
    // }
    // catch (const sql::SQLException &e)
    // {
    //     std::cout << "❌ SQL Error: " << e.what() << "\n";
    // }
    // catch (const std::exception &e)
    // {
    //     std::cout << "❌ General Error: " << e.what() << "\n";
    // }
    // catch (...)
    // {
    //     std::cout << "❌ Unknown error occurred.\n";
    // }
    // std::cout << khoHang << std::endl;
    // std::cout << khoHang.search_category("class Drink").search_price("0", "20000") << std::endl;

    crow::App<CORS> app;

    setup_user_routes(app);
    setup_signup_routes(app);
    setup_login_routes(app);
    setup_inf_user_routes(app);
    setup_update_inf_user_routes(app);
    setup_add_product_routes(app);
    setup_show_product_routes(app);
    setup_show_image_product_routes(app);
    setup_filter_product_routes(app);
    setup_add_product_to_cart_routes(app);
    setup_remove_product_from_cart_routes(app);
    setup_show_cart_routes(app);
    setup_checkout_routes(app);
    setup_show_bill_routes(app);

    app.port(18080).multithreaded().run();
    return 0;
}
