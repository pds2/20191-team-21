#ifndef STORAGE_H_PDS
#define STORAGE_H_PDS

#include "clothes.h"
#include "sunglasses.h"
#include "shoes.h"
#include <memory>

class Storage {
    map<shared_ptr<Product>, unsigned int> _storage;
public:
    Storage() {};
    Storage(string file_address);
    // MAP FUNCTIONS
    virtual void add_product(string product) = 0;
    virtual void add_product (const shared_ptr<Product> product, unsigned int quantity) = 0;

    virtual void remove_product(string product) = 0;
    virtual void remove_product (const shared_ptr<Product> product, unsigned int quantity) = 0;


    virtual void list_products() const = 0;
};

#endif //STORAGE_H_PDS