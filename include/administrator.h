#ifndef ADMIN_H_PDS
#define ADMIN_H_PDS

#include "user.h"

class Admin : public User {

  public:
    Admin(string name, string login, string password);

    void add_product_storage();
    void change_product_quantity();
    void change_product_price();
    void remove_product();
    void show_storage();

};

#endif
