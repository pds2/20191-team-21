#ifndef USER_H_PDS
#define USER_H_PDS

#include <iostream>
#include <string>
#include <fstream>
#include "product.h"
#include "cart.h"

using namespace std;

class User {

  string _name;
  string _login;
  string _password;

  public:

    void set_name(string name);
    void set_login(string login);
    void set_password(string password);

    string get_name();
    string get_login();
    string get_password();

};

#endif