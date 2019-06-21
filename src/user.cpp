#include "user.h"

//CONSTRUCTOR
User::User() {
}

User::User(string name, string login, string password, bool admin) {
    this->_name = std::move(name);
    this->_login = std::move(login);
    this->_password = std::move(password);
    this->_admin = admin;
}

void User::set_user(string name, string login, string password, bool admin){
    this->_name = std::move(name);
    this->_login = std::move(login);
    this->_password = std::move(password);
    this->_admin = admin;
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
bool User::is_admin(){
    return this->_admin;
}
void User::set_admin(bool a){
    this->_admin = a;
}
