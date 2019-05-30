#ifndef USER_H_PDS
#define USER_H_PDS

#include <iostream>
#include <string>
#include <fstream>
#include "product.h"
#include "cart.h"

using namespace std;

class User {
public:
    //attributes
    string _name;
    string _login;
    string _password;

    //methods
    virtual string get_name() = 0;
    virtual string get_login() = 0;
    virtual string get_password() = 0;

};

#endif //USER_H_PDS