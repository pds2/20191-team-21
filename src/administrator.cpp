#include <utility>

#include "administrator.h"

//CONSTRUCTOR
Admin::Admin(string name, string login, string password) {
    this->_name = std::move(name);
    this->_login = std::move(login);
    this->_password = std::move(password);
}

//GETTERS
string Admin::get_name(){
    return this->_name;
};
string Admin::get_login(){
    return this->_login;
};
string Admin::get_password(){
    return this->_password;
};


//ATTRIBUTES
void add_product_storage() {

//arquivo

}


void change_product_quantity() {

//arquivo

}


void change_product_price() {

//arquivo

}


void remove_product() {

//arquivo

}


void show_storage() {

//arquivo

}