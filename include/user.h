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
    virtual string get_name();
    virtual string get_login();
    virtual string get_password();

};

#endif //USER_H_PDS
