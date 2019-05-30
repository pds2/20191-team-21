#include <utility>

#include "product.h"

//CONSTRUCTOR
Product::Product(double price, int _quantity, string type, string color, string brand){
    this->_price = price;
    this->_quantity = _quantity;
    this->_brand = std::move(brand);
    this->_color = std::move(color);
    this->_type = std::move(type);
};

//SETTERS
void Product::set_type(string type) {
    this->_type = std::move(type);
}


void Product::set_brand(string brand) {
    this->_brand = std::move(brand);
}


void Product::set_color(string color) {
    this->_type = std::move(color);
}

void Product::set_price(double price){
    this->_price = price;
};
void Product::set_quantity(int quantity){
    this->_quantity = quantity;
};


//GETTERS
double Product::get_price(){
    return this->_price;
}

int Product::get_quantity(){
    return this->_quantity;
}

string Product::get_type() {
    return this->_type;
}

string Product::get_brand() {
    return this->_brand;
}

string Product::get_color() {
    return this->_color;
}
