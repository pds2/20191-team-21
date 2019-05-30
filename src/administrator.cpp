#include <utility>
#include "administrator.h"

//CONSTRUCTOR
Admin::Admin(string name, string login, string password) : User(std::move(name), std::move(login), std::move(password))
    {};

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
void Admin::add_product_storage() {

//arquivo

}


void Admin::change_product_quantity() {

//arquivo

}


void Admin::change_product_price() {

//arquivo

}


void Admin::remove_product() {

//arquivo

}

void Admin::show_storage() {

//arquivo

}