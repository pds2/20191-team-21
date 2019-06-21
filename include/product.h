#ifndef PRODUCT_H_PDS
#define PRODUCT_H_PDS

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <utility>
#include <memory>

#include "idmaker.h"

#define FEATURE_LIST { "TYPE", "MODEL", "COLOR", "SIZE" }


using namespace std;

class Product {
private:
    map<string, string> _features;

    double _price;
    unsigned int _quantity;


public:
    string _product_id;

//CONSTRUCTOR
    Product();
    Product(map<string, string> features, double price, unsigned int quantity);

    void create_feature();
    string generate_id(map<string, string> features);

//SETTERS
    void set_feature(string feature, string value);
    void update_quantity(unsigned int add);
    void set_quantity(unsigned int quantity);
    void set_price(double price);

//GETTERS
    string get_feature(string feature);   
    double get_price() const;
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

//DATABASE
    void save_to(std::ostream &out);
    static shared_ptr<Product> read_from(std::istream &in);
//PRINTER
    void print() const;
};

#endif //PRODUCT_H_PDS
