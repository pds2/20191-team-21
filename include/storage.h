#ifndef STORAGE_H_PDS
#define STORAGE_H_PDS

#define DB_FILE "test_db"
#include "product.h"

class Storage {
protected:
    map<string, shared_ptr<Product>> _storage;
public:
    Storage();

    void add_product(shared_ptr<Product> product);
    void remove_product(string product_id);

    map<string, shared_ptr<Product>>::iterator get_product_tuple (string product_id);
    shared_ptr<Product> get_product (string product_id);

    void list_products() const;

    void clear();
};

#endif //STORAGE_H_PDS