#ifndef SHOES_H_PDS
#define SHOES_H_PDS

#include "product.h"

class Shoes : public Product {

    int _size;

public:
    //CONSTRUCTOR
    Shoes(string type, string brand, string color, int size, double price);

    //SETTERS
    void set_type(string type) override;
    void set_brand(string brand) override;
    void set_color(string color) override;
    void set_size(int size);
    void set_price(double price) override;

    //GETTERS
    double get_price() const override;
    string get_type() const override;
    string get_brand() const override;
    string get_color() const override;
    int get_size();

    //OPERATORS
    bool operator<(const Shoes &shoes) const;
    //PRINT
    virtual void print() const override;
};

#endif //SHOES_H_PDS
