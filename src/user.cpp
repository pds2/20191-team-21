#include "user.h"

//CONSTRUCTOR
User::User(string name, string login, string password) {
    this->_name = std::move(name);
    this->_login = std::move(login);
    this->_password = std::move(password);
}

//GETTERS
string User::get_name(){
    return this->_name;
}
string User::get_login(){
    return this->_login;
}
string User::get_password(){
    return this->_password;
}