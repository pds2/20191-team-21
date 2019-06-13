#ifndef STORAGE_BASKET_H_PDS
#define STORAGE_BASKET_H_PDS

#include "storage.h"

class Basket : public Storage {

public:
    Basket();
    double get_total_price() const;

    void view_basket() const;
};

#endif //STORAGE_BASKET_H_PDS