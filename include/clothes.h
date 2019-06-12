#ifndef CLOTHES_H_PDS
#define CLOTHES_H_PDS

#include "product.h"

class Clothes : public Product {

    string _size;

public:
    //CONSTRUCTOR
    Clothes(string type, string brand, string color, string size, double price, int quantity);

    //SETTERS
    void set_type(string type) override;
    void set_brand(string brand) override;
    void set_color(string color) override;
    void set_size(string size);
    void set_price(double price) override;
    void set_quantity(int quantity) override;

    //GETTERS
    double get_price() override;
    int get_quantity() override;
    string get_type() override;
    string get_brand() override;
    string get_color() override;
    string get_size();

    //OPERATORS
    bool operator<(const Clothes &clothes) const;

    //PRINTER
    virtual void print() const override;

};

#endif //CLOTHES_H_PDS
