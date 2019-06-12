#ifndef PRODUCT_H_PDS
#define PRODUCT_H_PDS

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

class Product {
protected:
    string _product_id;
public:
    double _price;
    int _quantity;
    string _type;
    string _color;
    string _brand;
//CONSTRUCTOR
    Product(double price, int quantity, string type, string color, string brand);
//    Product(double price, int quantity, string type, string color, string brand, string product_id);


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

//OPERATORS
    bool operator>(const Product &product) const;
    bool operator>=(const Product &product) const;
    bool operator<(const Product &product) const;
    bool operator<=(const Product &product) const;
    bool operator!=(const Product &product) const;
    bool operator==(const Product &product) const;
    bool equals(const Product &product) const;

//PRINTER
    virtual void print() const = 0;
};

#endif //PRODUCT_H_PDS
