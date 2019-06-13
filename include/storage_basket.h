#ifndef BASKET_STORAGE_H_PDS
#define BASKET_STORAGE_H_PDS

#include "storage.h"

class Basket : public Storage {
private:
    double _total_price;

public:
    Basket();
    void calculate_total_price();
};

#endif //STORAGE_BASKET_H_PDS