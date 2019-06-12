#ifndef PRODUCT_H_PDS
#define PRODUCT_H_PDS

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>

#define ID_CLOTHES "000"
#define ID_SHOES "001"
#define ID_SUNGLASSES "002"

using namespace std;

class Product {
protected:
    string _product_id;
public:
    double _price;
    string _type;
    string _color;
    string _brand;
//CONSTRUCTOR
    Product(double price, string type, string color, string brand);


//SETTERS
    virtual void set_price(double price);
    virtual void set_type(string type);
    virtual void set_color(string color);
    virtual void set_brand(string brand);

//GETTERS
    virtual double get_price();
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
