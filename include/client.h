#ifndef CLIENT_H_PDS
#define CLIENT_H_PDS

#include <memory>

#include "user.h"
#include "cart.h"
#include "clothes.h"
#include "shoes.h"
#include "sunglasses.h"

class Client : public User {
    //attributes
//    Cart client_cart;
    map<shared_ptr<Product>, unsigned int> cart;

public:
    //CONSTRUCTOR
    Client(string name, string login, string password);

    //GETTERS
    string get_name() override;
    string get_login() override;
    string get_password() override;

    //METHODS
    void search_product();
    void see_cart();
    // MAP FUNCTIONS
    void add_product (const shared_ptr<Product> product, unsigned int quantity);
    void remove_product (const shared_ptr<Product> product, unsigned int quantity);
    void list_products();
};

#endif //CLIENT_H_PDS
