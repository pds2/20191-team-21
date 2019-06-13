#include "doctest.h"

#include "user.h"
// #include "user_admin.h"
// #include "user_client.h"

#include "product.h"
#include "product_clothes.h"
#include "product_shoes.h"
#include "product_sunglasses.h"

#include "storage.h"
#include "storage_warehouse.h"
#include "storage_basket.h"

TEST_CASE("Test Cart Creation") {
//    CHECK_NOTHROW(Cart());
}

TEST_CASE("Basket testing") {
    cout << endl << endl << endl << "TESTING BASKET" << endl;
    shared_ptr<Basket> basket_1 (new Basket());
    auto roupa = make_shared<Clothes>("tipo", "marca", "cor", "tamanho", 2.0, 5);
    basket_1->add_product(roupa->get_id(), roupa);
    auto sg = make_shared<Sunglasses>("tipo", "marca", "cor", 2.0, 1);
    basket_1->add_product(sg->get_id(), sg);
    basket_1->view_basket();
}

TEST_CASE("Warehouse") {
    cout << endl << endl << endl << "TESTING WAREHOUSE" << endl;
    shared_ptr<Warehouse> warehouse_1 (new Warehouse());
    auto product = make_shared<Clothes>("clothes", "brand", "color", "str_size", 2.0, 1);
    warehouse_1->add_product(product->get_id(), product);
    warehouse_1->list_products();
}

TEST_CASE("Test Admin Creation") {
    //CHECK_NOTHROW(User("John Snow", "jsn", "8888!!!@@##$%*"));
    //CHECK_NOTHROW(User("John Snow", "@  jsn", "8888!!!@@##$%*"));
    //CHECK_NOTHROW(User("John Snow__", "@jsn", "8888!!!@@##$%*"));
    //CHECK_NOTHROW(User("John Snow123", "@jsn", "8888!!!@@##$%*"));
    //CHECK_NOTHROW(User("John Snow", "@asdasjsn", "8888!!!@@##$%*"));
    //CHECK_NOTHROW(User("John Snow", "@jsn", "8888!!!@@##$%*"));
    //CHECK_NOTHROW(User("John Snow", "@jsn", "8888!!!@@##$%*"));
    //CHECK_NOTHROW(User("John Snow", "@jsn", "8888!!!@@##$%*"));
    //CHECK_NOTHROW(User("John Snow", "@jsn", "8888!!!@@##$%*"));
}

TEST_CASE("Test User Creation") {
//    CHECK_NOTHROW(Admin("John Snow", "jsn", "8888!!!@@##$%*"));
//    CHECK_NOTHROW(Admin("John Snow", "@  jsn", "8888!!!@@##$%*"));
//    CHECK_NOTHROW(Admin("John Snow__", "@jsn", "8888!!!@@##$%*"));
//    CHECK_NOTHROW(Admin("John Snow123", "@jsn", "8888!!!@@##$%*"));
//    CHECK_NOTHROW(Admin("John Snow", "@asdasjsn", "8888!!!@@##$%*"));
//    CHECK_NOTHROW(Admin("John Snow", "@jsn", "8888!!!@@##$%*"));
//    CHECK_NOTHROW(Admin("John Snow", "@jsn", "8888!!!@@##$%*"));
//    CHECK_NOTHROW(Admin("John Snow", "@jsn", "8888!!!@@##$%*"));
//    CHECK_NOTHROW(Admin("John Snow", "@jsn", "8888!!!@@##$%*"));
}

TEST_CASE("Test Product Creation") {
  //  CHECK_NOTHROW(Product(5.0, 2, "cor", "tamanho", "marca"));
}

TEST_CASE("Test Clothes Creation") {
    CHECK_NOTHROW(Clothes("tipo", "marca", "cor", "tamanho", 2.0, 1));

}

TEST_CASE("Test Shoes Creation") {
    CHECK_NOTHROW(Shoes("tipo", "marca", "cor", 38, 2.0, 1));
}

TEST_CASE("Test Sunglasses Creation") {
    CHECK_NOTHROW(Sunglasses("tipo", "marca", "cor", 2.0, 10));
}

//cart
//menu