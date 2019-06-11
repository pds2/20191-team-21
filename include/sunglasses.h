#ifndef SUNGLASSES_H_PDS
#define SUNGLASSES_H_PDS

#include "product.h"

class Sunglasses : public Product {

    int _size = 0;

public:
    //CONSTRUCTOR
    Sunglasses(string brand, string color, int quantity, double price);

    //SETTERS
    void set_type(string type) override;
    void set_brand(string brand) override;
    void set_color(string color) override;
    void set_size(int size);
    void set_price(double price) override;
    void set_quantity(int quantity) override;

    //GETTERS
    double get_price() override;
    int get_quantity() override;
    string get_type() override;
    string get_brand() override;
    string get_color() override;
    int get_size();

};

#endif //SUNGLASSES_H_PDS
