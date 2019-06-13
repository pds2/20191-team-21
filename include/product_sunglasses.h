#ifndef SUNGLASSES_H_PDS
#define SUNGLASSES_H_PDS

#include "product.h"

class Sunglasses : public Product {

    int _size = 0;

public:
    //CONSTRUCTOR
    Sunglasses(string type, string brand, string color, double price, unsigned int quantity);

    //SETTERS
    void set_size(int size);

    //GETTERS
    int get_size();

    //OPERATORS
    bool operator<(const Sunglasses &sunglasses) const;

    //PRINTER
    virtual void print() const override;
};

#endif //SUNGLASSES_H_PDS
