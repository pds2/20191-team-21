#ifndef SUNGLASSES_H_PDS
#define SUNGLASSES_H_PDS

#include "product.h"

class Sunglasses : public Product {

    int _size = 0;

public:
    //CONSTRUCTOR
    Sunglasses(string type, string brand, string color, double price);

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
    bool operator<(const Sunglasses &sunglasses) const;

    //PRINTER
    virtual void print() const override;
};

#endif //SUNGLASSES_H_PDS
