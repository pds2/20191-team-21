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
    void add_product(Clothes clothes, unsigned int quantity);
    void add_product(Shoes shoes, unsigned int quantity);
    void add_product(Sunglasses sunglasses, unsigned int quantity);

    void delete_product(Clothes clothes);
    void delete_product(Shoes shoes);
    void delete_product(Sunglasses sunglasses);

    void list_products();
    void list_products(string type);

    void list_shoes();
    void list_clothes();
    void list_sunglasses();
};

#endif //WAREHOUSE_H_PDS