#ifndef USER_H_PDS
#define USER_H_PDS

#include <utility>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class User {
public:
    //attributes
    bool _admin;
    string _name;
    string _login;
    string _password;

    //CONSTRUCTOR
    User(string name, string login, string password);

    //methods
    virtual string get_name() = 0;
    virtual string get_login() = 0;
    virtual string get_password() = 0;

};

#endif //USER_H_PDS
