#include "terminal.h"
#include <iostream>
#include <string.h>
#include <utility>
#include <stdio.h>

Terminal::Terminal(){
    shared_ptr<Basket> _basket;
    shared_ptr<Warehouse> _warehouse;
    map<string, function<void(Terminal*)>> _commands;

    _commands.emplace("help", &Terminal::c_print_help);
    _commands.emplace("list products", &Terminal::c_list_products);
    _commands.emplace("create product", &Terminal::c_create_product);
    _commands.emplace("warehouse remove product", &Terminal::c_rm_product_warehouse);
    _commands.emplace("warehouse clear", &Terminal::c_clear_warehouse);
    _commands.emplace("basket add product", &Terminal::c_add_product_basket);
    _commands.emplace("basket remove product", &Terminal::c_rm_product_basket);
    _commands.emplace("basket view", &Terminal::c_view_basket);
    _commands.emplace("basket checkout", &Terminal::c_checkout_basket);
    _commands.emplace("basket clear", &Terminal::c_clear_basket);
}
void Terminal::menu_home(){
    while(true){
        string cmd;
        cout << endl << "Digite um comando (help para a lista de opcoes): " << endl;
        cin >> cmd;
        cin.get();
        if (strcmp(cmd.c_str(), "exit") == 0){
            break;
        }
        this->_commands[cmd](this);
    }
}

void Terminal::print_greetings() const {
    cout << "Welcome " << this->_user->get_login() << "!" << endl;
}
//general
void Terminal::c_print_help() const {
    cout << "Ajuda e lista de comandos:" << endl;
}
void Terminal::c_list_products() const {
    this->_warehouse->list_products();
}
//admin
void Terminal::c_create_product() const {
    cout << endl << "Adicionando produto:" << endl;
    this->_warehouse->add_product(Input::product());
}
void Terminal::c_rm_product_warehouse() const {
    this->_warehouse->remove_product(Input::product_id());
}
void Terminal::c_clear_warehouse() const {
    this->_warehouse->clear();
}
//client
void Terminal::c_add_product_basket() const {
    this->_basket->add_product(_warehouse->get_product(Input::product_id()));
}
void Terminal::c_rm_product_basket() const {
    this->_basket->remove_product(Input::product_id());

}
void Terminal::c_view_basket() const {
    this->_basket->view_basket();
}
void Terminal::c_checkout_basket() const {
//    for (auto& i : this->_basket->_storage){
//        (this->_warehouse[i->first]).update_quantity((i->second)*(-1));
//    }
//    this->_basket->clear();
//    cout << endl << "Compra finalizada!" << endl;
}
void Terminal::c_clear_basket() const {
    this->_basket->clear();
}