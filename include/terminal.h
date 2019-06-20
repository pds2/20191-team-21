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
    map<string, function<void(Terminal*)>> _commands;
    unique_ptr<User> _user;
    shared_ptr<Basket> _basket;
    shared_ptr<Warehouse> _warehouse;
public:
    Terminal();

    void menu_home();
    void menu_confirm_purchase();
    void menu_product_to_warehouse();
    void menu_product_to_basket();

//general
    void c_list_products() const;
    void c_print_help() const;
//admin   
    void c_create_product() const;
    void c_edit_product() const;
    void c_rm_product_warehouse() const;
//client
    void c_add_product_basket() const;
    void c_rm_product_basket() const;
    void c_view_basket() const;
    void c_checkout_basket() const;
    void c_clear_basket() const;
    void c_clear_warehouse() const;

    void print_greetings() const;
};

#endif