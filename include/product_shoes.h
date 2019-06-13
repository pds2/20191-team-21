#ifndef SHOES_H_PDS
#define SHOES_H_PDS

#include "product.h"

class Shoes : public Product {

    int _size;

public:
    //CONSTRUCTOR
    Shoes(string type, string brand, string color, int size, double price, unsigned int quantity);

    //SETTERS
    void set_size(int size);

    //GETTERS
    int get_size();

    //OPERATORS
    bool operator<(const Shoes &shoes) const;
    
    //PRINT
    virtual void print() const override;
};

#endif //SHOES_H_PDS
