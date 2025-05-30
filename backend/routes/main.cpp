#include "Route.h"

int main()
{

    crow::App<CORS> app;

    setup_user_routes(app);
    setup_signup_routes(app);
    setup_login_routes(app);
    setup_inf_user_routes(app);
    setup_update_inf_user_routes(app);
    setup_update_image_user_routes(app);
    setup_show_user_routes(app);
    setup_add_product_routes(app);
    setup_show_product_routes(app);
    setup_show_image_user_routes(app);
    setup_show_image_product_routes(app);
    setup_add_product_to_cart_routes(app);
    setup_remove_product_from_cart_routes(app);
    setup_show_cart_routes(app);
    setup_checkout_routes(app);
    setup_show_bill_routes(app);

    app.port(18080).multithreaded().run();
    return 0;
}
