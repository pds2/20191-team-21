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
    unsigned int _quantity;
//CONSTRUCTOR
    Product(double price, string type, string color, string brand, unsigned int quantity);

//SETTERS
    void set_price(double price);
    void set_type(string type);
    void set_color(string color);
    void set_brand(string brand);
    void set_quantity(unsigned int quantity);
    void update_quantity(unsigned int add);

//GETTERS
    double get_price() const;
    string get_type() const;
    string get_color() const;
    string get_brand() const;
    unsigned int get_quantity() const;
    string get_id() const;

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
