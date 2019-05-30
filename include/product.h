#ifndef PRODUCT_H_PDS
#define PRODUCT_H_PDS

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Product {
public:
    double _price;
    int _quantity;
    string _type;
    string _color;
    string _brand;
//CONSTRUCTOR
    Product(double price, int _quantity, string type, string color, string brand);


//SETTERS
    virtual void set_price(double price);
    virtual void set_quantity(int quantity);
    virtual void set_type(string type);
    virtual void set_color(string color);
    virtual void set_brand(string brand);

//GETTERS
    virtual double get_price();
    virtual int get_quantity();
    virtual string get_type();
    virtual string get_color();
    virtual string get_brand();

};

#endif //PRODUCT_H_PDS
