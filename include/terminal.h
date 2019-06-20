#ifndef TERMINAL_H_PDS
#define TERMINAL_H_PDS

#include "storage_basket.h"
#include "storage_warehouse.h"
#include "user.h"
#include "input.h"
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <typeinfo>
#include <typeindex>
#include <cassert>
#include <functional>

class Terminal {
    using TerminalFPtr = function<void(void)>;

    map<string, TerminalFPtr> _commands;

    static User _user;
    static Basket _basket;
    static Warehouse _warehouse;
public:
    Terminal();

    void menu_home();
    void menu_confirm_purchase();
    void menu_product_to_warehouse();
    void menu_product_to_basket();

//general
    static void c_list_products();
    static void c_print_help();
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

    void print_greetings() const;
};

#endif