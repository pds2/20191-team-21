#ifndef CLOTHES_H_PDS
#define CLOTHES_H_PDS

#include "product.h"

class Clothes : public Product {
private:
    string _size;

public:
    //CONSTRUCTOR
    Clothes(string type, string brand, string color, string size, double price);

    //SETTERS
    void set_type(string type) override;
    void set_brand(string brand) override;
    void set_color(string color) override;
    void set_size(string size);
    void set_price(double price) override;

    //GETTERS
    double get_price() override;
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
