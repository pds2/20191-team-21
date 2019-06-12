#ifndef WAREHOUSE_H_PDS
#define WAREHOUSE_H_PDS

#include "clothes.h"
#include "sunglasses.h"
#include "shoes.h"

class Warehouse {

    map<Clothes, unsigned int> _clothes;
    map<Shoes, unsigned int> _shoes;
    map<Sunglasses, unsigned int> _sunglasses;

public:
    //CONSTRUCTOR

    // OPERATIONS
    void add_product(Clothes clothes);
    void add_product(Shoes shoes);
    void add_product(Sunglasses sunglasses);

    void remove_product(Clothes clothes);
    void remove_product(Shoes shoes);
    void remove_product(Sunglasses sunglasses);

    void list_products();
    void list_products(string type);

};

#endif //WAREHOUSE_H_PDS