#ifndef USER_H_PDS
#define USER_H_PDS

#include <utility>
#include <iostream>
#include <string>
#include <fstream>
#include <memory>

#define ADMIN_KEY "alohomora"

using namespace std;

class User {
public:
    //attributes
    bool _admin;
    string _name;
    string _login;
    string _password;
    

    //CONSTRUCTOR
    User();
    User(string name, string login, string password, bool _admin);
    
    //setter
    void set_user(string name, string login, string password, bool admin);

    //methods
    string get_name();
    string get_login();
    string get_password();
    bool is_admin();

    void set_admin(bool a);
};

#endif //USER_H_PDS
