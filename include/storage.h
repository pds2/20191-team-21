#ifndef STORAGE_H_PDS
#define STORAGE_H_PDS

#include "clothes.h"
#include "sunglasses.h"
#include "shoes.h"
#include <memory>

class Storage {
protected:
    map<string, shared_ptr<Product>> _storage;
public:
    Storage();

//    Storage(string file_address);
    // MAP FUNCTIONS
    void add_product(string product_id, shared_ptr<Product> product);
    void remove_product(map<string, shared_ptr<Product>>::iterator product_tuple);
    void remove_product(string product_id);
    map<string, shared_ptr<Product>>::iterator find_tuple (const shared_ptr<Product> product) const;

    virtual void list_products() const;
};

#endif //STORAGE_H_PDS

