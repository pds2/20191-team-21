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

typedef void (*voidFunctionType)(void);

struct Commands {

    std::map<std::string,std::pair<voidFunctionType,std::type_index>> m1;

    template<typename T>
    void insert(std::string s1, T f1){
        auto tt = std::type_index(typeid(f1));
        m1.insert(std::make_pair(s1,
                        std::make_pair((voidFunctionType)f1,tt)));
    }

    template<typename T,typename... Args>
    T searchAndCall(std::string s1, Args&&... args){
        auto mapIter = m1.find(s1);
        /*chk if not end*/
        auto mapVal = mapIter->second;

        // auto typeCastedFun = reinterpret_cast<T(*)(Args ...)>(mapVal.first); 
        auto typeCastedFun = (T(*)(Args ...))(mapVal.first); 

        //compare the types is equal or not
        assert(mapVal.second == std::type_index(typeid(typeCastedFun)));
        return typeCastedFun(std::forward<Args>(args)...);
    }
};

class Terminal {
    Commands _commands;
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