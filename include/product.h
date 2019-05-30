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
    virtual void set_price(double price) = 0;
    virtual void set_quantity(int quantity) = 0;
    virtual void set_type(string type) = 0;
    virtual void set_color(string color) = 0;
    virtual void set_brand(string brand) = 0;
    virtual void set_size(string size) = 0;
    virtual void set_size(int size) = 0;

//GETTERS
    virtual double get_price() = 0;
    virtual int get_quantity() = 0;
    virtual string get_type() = 0;
    virtual string get_color() = 0;
    virtual string get_brand() = 0;

};

#endif //PRODUCT_H_PDS