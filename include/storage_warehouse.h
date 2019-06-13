#ifndef WAREHOUSE_STORAGE_H_PDS
#define WAREHOUSE_STORAGE_H_PDS

#include "storage.h"

class Warehouse : Storage {
public:
    Warehouse(string file_address);
    void load_db();
    void save_db();
    // MAP FUNCTIONS
    virtual void add_product (const shared_ptr<Product> product, unsigned int quantity) override;
    virtual void remove_product (const shared_ptr<Product> product, unsigned int quantity) override;
};

#endif //WAREHOUSE_STORAGE_H_PDS