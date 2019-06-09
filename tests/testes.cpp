#include "doctest.h"

#include "user.h"
#include "administrator.h"
#include "cart.h"

#include "clothes.h"

#include "product.h"
#include "shoes.h"
#include "sunglasses.h"
#include "user.h"

// #include "menu.h"
#include "client.h"

TEST_CASE("Test Cart Creation") {
    CHECK_NOTHROW(Cart());
}

TEST_CASE("Cart testing") {
    Client cliente_1 = Client("John Snow", "jsn", "8888!!!@@##$%*");
    cliente_1.add_product(Clothes("tipo", "marca", "cor", "tamanho", 2.0, 1), 1);
    cliente_1.list_products();
}

TEST_CASE("Test Admin Creation") {
    CHECK_NOTHROW(User("John Snow", "jsn", "8888!!!@@##$%*"));
    CHECK_NOTHROW(User("John Snow", "@  jsn", "8888!!!@@##$%*"));
    CHECK_NOTHROW(User("John Snow__", "@jsn", "8888!!!@@##$%*"));
    CHECK_NOTHROW(User("John Snow123", "@jsn", "8888!!!@@##$%*"));
    CHECK_NOTHROW(User("John Snow", "@asdasjsn", "8888!!!@@##$%*"));
    CHECK_NOTHROW(User("John Snow", "@jsn", "8888!!!@@##$%*"));
    CHECK_NOTHROW(User("John Snow", "@jsn", "8888!!!@@##$%*"));
    CHECK_NOTHROW(User("John Snow", "@jsn", "8888!!!@@##$%*"));
    CHECK_NOTHROW(User("John Snow", "@jsn", "8888!!!@@##$%*"));
}

TEST_CASE("Test User Creation") {
    CHECK_NOTHROW(Admin("John Snow", "jsn", "8888!!!@@##$%*"));
    CHECK_NOTHROW(Admin("John Snow", "@  jsn", "8888!!!@@##$%*"));
    CHECK_NOTHROW(Admin("John Snow__", "@jsn", "8888!!!@@##$%*"));
    CHECK_NOTHROW(Admin("John Snow123", "@jsn", "8888!!!@@##$%*"));
    CHECK_NOTHROW(Admin("John Snow", "@asdasjsn", "8888!!!@@##$%*"));
    CHECK_NOTHROW(Admin("John Snow", "@jsn", "8888!!!@@##$%*"));
    CHECK_NOTHROW(Admin("John Snow", "@jsn", "8888!!!@@##$%*"));
    CHECK_NOTHROW(Admin("John Snow", "@jsn", "8888!!!@@##$%*"));
    CHECK_NOTHROW(Admin("John Snow", "@jsn", "8888!!!@@##$%*"));
}

TEST_CASE("Test Product Creation") {
    CHECK_NOTHROW(Product(5.0, 2, "cor", "tamanho", "marca"));
}

TEST_CASE("Test Clothes Creation") {
    CHECK_NOTHROW(Clothes("tipo", "marca", "cor", "tamanho", 2.0, 1));

}

TEST_CASE("Test Shoes Creation") {
    CHECK_NOTHROW(Shoes("tipo", "marca", "cor", 38, 2.0, 1));
}

TEST_CASE("Test Menu Creation") {
    CHECK_NOTHROW(Shoes("tipo", "marca", "cor", 38, 2.0, 1));
}

//cart
//menu