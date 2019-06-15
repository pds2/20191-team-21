#ifndef TERMINAL_H_PDS
#define TERMINAL_H_PDS

#include "storage_basket.h"
#include "storage_warehouse.h"
#include "user.h"
#include "factory.h"

class Terminal {
    unique_ptr<User> _user;
    shared_ptr<Basket> _basket;
    shared_ptr<Warehouse> _warehouse;

    map<string, unique_ptr<void>> commands;

public:
    Terminal();

    void menu_home();
    void menu_confirm_purchase();
    void menu_product_to_warehouse();
    void menu_product_to_basket();

//general
    static void c_list_products();
//admin   
    static void c_create_product();
    static void c_edit_product();
    static void c_rm_product_warehouse();
//client
    static void c_add_product_basket();
    static void c_rm_product_basket();
    static void c_view_basket();
    static void c_checkout_basket();
    static void c_clear_basket();
    static void c_clear_warehouse();

    void print_greetings();
    void print_help();
};

#endif