#include "doctest.h"

#include "user.h"
// #include "user_admin.h"
// #include "user_client.h"

#include "product.h"

#include "storage.h"
#include "storage_warehouse.h"
#include "storage_basket.h"

#include <stdio.h>
#include <string.h>

#define FEAT_MAP_1 {{"TYPE", "tipo1"}, {"MODEL", "modelo1"}, {"COLOR", "hue1"}, {"SIZE","s1"}}
#define FEAT_MAP_2 {{"TYPE", "tipo2"}, {"MODEL", "modelo2"}, {"COLOR", "hue2"}, {"SIZE","s2"}}
#define FEAT_MAP_3 {{"TYPE", "tipo3"}, {"MODEL", "modelo3"}, {"COLOR", "hue3"}, {"SIZE","s3"}}
#define FEAT_MAP_4 {{"TYPE", "tipo4"}, {"MODEL", "modelo4"}, {"COLOR", "hue4"}, {"SIZE","s4"}}
#define FEAT_MAP_5 {{"TYPE", "tipo5"}, {"MODEL", "modelo5"}, {"COLOR", "hue5"}, {"SIZE","s5"}}
#define PRICE_1 10.0
#define PRICE_2 20.0
#define PRICE_3 30.0
#define PRICE_4 40.0
#define PRICE_5 50.0
#define QTY_1 1
#define QTY_2 2
#define QTY_3 3
#define QTY_4 4
#define QTY_5 5


TEST_CASE("Test Cart Creation") {
//    CHECK_NOTHROW(Cart());
}

TEST_CASE("Product In/Out file") {
    cout << endl << endl << endl << "TESTING in/out" << endl;

    shared_ptr<Warehouse> warehouse_1 (new Warehouse());

    Product item1(FEAT_MAP_1, PRICE_1, QTY_1);
    Product item2(FEAT_MAP_2, PRICE_2, QTY_2);
    Product item3(FEAT_MAP_3, PRICE_3, QTY_3);
    Product item4(FEAT_MAP_4, PRICE_4, QTY_4);
    Product item5(FEAT_MAP_5, PRICE_5, QTY_5);

    ofstream out("test_db");
    item1.save_to(out);
    item2.save_to(out);
    item3.save_to(out);
    item4.save_to(out);
    item5.save_to(out);
    out.close();
    
    ifstream in("test_db");
    while (!in.eof()) {
        auto p = Product::read_from(in);

        if  (p->get_id().size() > 3) {
            warehouse_1->add_product(p);
            cout << "p" <<endl;
        }

    }
    in.close();

    warehouse_1->list_products();
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