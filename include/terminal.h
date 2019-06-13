#ifndef TERMINAL_H_PDS
#define TERMINAL_H_PDS

#include "storage_basket.h"
#include "storage_warehouse.h"
#include "user.h"

class Terminal {
    unique_ptr<User> _user;
    shared_ptr<Basket> _basket;
    shared_ptr<Warehouse> _warehouse;

public:
    Terminal();

    void menu_home();
    void menu_confirm_purchase();
    void menu_product_to_warehouse();
    void menu_product_to_basket();

    void print_greetings();
    void print_help();
};

#endif