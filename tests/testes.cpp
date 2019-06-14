#include "doctest.h"

#include "user.h"
// #include "user_admin.h"
// #include "user_client.h"

#include "product.h"

#include "storage.h"
#include "storage_warehouse.h"
#include "storage_basket.h"

TEST_CASE("Test Cart Creation") {
//    CHECK_NOTHROW(Cart());
}

TEST_CASE("Basket testing") {
    cout << endl << endl << endl << "TESTING BASKET" << endl;
    shared_ptr<Basket> basket_1 (new Basket());

    map<string, string> features1 = {{"tipo", "abc"}, {"marca", "stark"}, {"cor","blue"}, {"tamanho", "unico"}}; 
    map<string, string> features2 = {{"tipo", "111"}, {"marca", "targ"}, {"cor","red"}, {"tamanho", "gg"}};
    auto roupa = make_shared<Product>(features1, 2.0, 5);   
    auto sg = make_shared<Product>(features2, 1.0, 5);
    basket_1->add_product(roupa);
    basket_1->add_product(sg);
    basket_1->view_basket();
}

TEST_CASE("Warehouse") {
    cout << endl << endl << endl << "TESTING WAREHOUSE" << endl;
    shared_ptr<Warehouse> warehouse_1 (new Warehouse());

    map<string, string> features1 = {{"tipo", "abc"}, {"marca", "stark"}, {"cor","blue"}, {"tamanho", "unico"}}; 
    map<string, string> features2 = {{"tipo", "111"}, {"marca", "targ"}, {"cor","red"}, {"tamanho", "gg"}};
    auto roupa = make_shared<Product>(features1, 2.0, 5);   
    auto sg = make_shared<Product>(features2, 1.0, 5);
    warehouse_1->add_product(roupa);
    warehouse_1->add_product(sg);
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

//cart
//menu