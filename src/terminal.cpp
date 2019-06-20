#include "terminal.h"
#include <iostream>
#include <string.h>
#include <utility>
#include <stdio.h>

//User Terminal::_user;
Basket Terminal::_basket;
Warehouse Terminal::_warehouse;

Terminal::Terminal(){

    Terminal::_commands.emplace("help", Terminal::c_print_help);
    Terminal::_commands.emplace("help", Terminal::c_print_help);
    Terminal::_commands.emplace("list products", Terminal::c_list_products);
    Terminal::_commands.emplace("create product", Terminal::c_create_product);
    Terminal::_commands.emplace("warehouse remove product", Terminal::c_rm_product_warehouse);
    Terminal::_commands.emplace("warehouse clear", Terminal::c_clear_warehouse);
    Terminal::_commands.emplace("basket add product", Terminal::c_add_product_basket);
    Terminal::_commands.emplace("basket remove product", Terminal::c_rm_product_basket);
    Terminal::_commands.emplace("basket view", Terminal::c_view_basket);
    Terminal::_commands.emplace("basket checkout", Terminal::c_checkout_basket);
    Terminal::_commands.emplace("basket clear", Terminal::c_clear_basket);
}
void Terminal::menu_home(){
    while(true){
        string cmd;
        cout << endl << "Digite um comando (help para a lista de opcoes): " << endl;
        cin >> cmd;
        cin.get();
        cout << endl << strcmp(cmd.c_str(), "help") << endl; 
        if (strcmp(cmd.c_str(), "exit") == 0){
            break;
        }
        Terminal::_commands[cmd]();
    }

}

void Terminal::print_greetings() const {
   // cout << "Welcome " << Terminal::_user.get_login() << "!" << endl;
}
//general
void Terminal::c_print_help(){
    cout << "Ajuda e lista de comandos:" << endl;
}
void Terminal::c_list_products(){
    Terminal::_warehouse.list_products();
}
//admin
void Terminal::c_create_product(){
    cout << endl << "Adicionando produto:" << endl;
    Terminal::_warehouse.add_product(Input::product());
}
void Terminal::c_rm_product_warehouse(){
    Terminal::_warehouse.remove_product(Input::product_id());
}
void Terminal::c_clear_warehouse(){
    Terminal::_warehouse.clear();
}
//client
void Terminal::c_add_product_basket(){
    Terminal::_basket.add_product(_warehouse.get_product(Input::product_id()));
}
void Terminal::c_rm_product_basket(){
    Terminal::_basket.remove_product(Input::product_id());

}
void Terminal::c_view_basket(){
    Terminal::_basket.view_basket();
}
void Terminal::c_checkout_basket(){
//    for (auto& i : Terminal::_basket._storage){
//        (Terminal::_warehouse[i.first]).update_quantity((i.second)*(-1));
//    }
//    Terminal::_basket.clear();
//    cout << endl << "Compra finalizada!" << endl;
}
void Terminal::c_clear_basket(){
    Terminal::_basket.clear();
}