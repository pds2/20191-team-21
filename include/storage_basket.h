#ifndef BASKET_STORAGE_H_PDS
#define BASKET_STORAGE_H_PDS

#include "storage.h"

class Basket : public Storage {
    Basket(string file_address);
    void add_product (string product_id) override;
    void remove_product (string product_id) override;
};

#endif //STORAGE_BASKET_H_PDS