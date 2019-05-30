#ifndef CART_H_PDS
#define CART_H_PDS

#include "product.h"
#include "clothes.h"
#include "shoes.h"
#include "sunglasses.h"

class Cart {

  vector<Product> cart_products;

  public:
    void get_products();
    double get_total_price();
    void add_clothes(Clothes c_added, int quantity);
    void add_shoes(Shoes s_added, int quantity);
    void add_sunglasses(Sunglasses sg_added, int quantity);
    void remove_product();
    void cancel_purchase();
    void finish_purchase();

};

#endif
