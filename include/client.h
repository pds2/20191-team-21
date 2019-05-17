#ifndef CLIENT_H_PDS
#define CLIENT_H_PDS

#include "user.h"
#include "cart.h"
#include "clothes.h"
#include "shoes.h"
#include "sunglasses.h"

class Client : public User {

  Cart client_cart;

  public:
    Client(string name, string login, string password);

    void search_product();
    void see_cart();

};

#endif