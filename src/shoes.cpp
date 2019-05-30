#include "shoes.h"


//CONSTRUCTOR
Shoes::Shoes(string type, string brand, string color, int size, double price, int quantity)
        : Product(price, quantity, std::move(type), std::move(color), std::move(brand)) {
    this->_size = size;
}

//SETTERS
void Shoes::set_type(string type) {
    this->_type = std::move(type);
}


void Shoes::set_brand(string brand) {
    this->_type = std::move(brand);
}


void Shoes::set_color(string color) {
    this->_type = std::move(color);
}


void Shoes::set_size(int size) {
    this->_type = std::move(size);
}

void Shoes::set_price(double price){
    this->_price = price;
};
void Shoes::set_quantity(int quantity){
    this->_quantity = quantity;
};


//GETTERS
double Shoes::get_price(){
    return this->_price;
}

int Shoes::get_quantity(){
    return this->_quantity;
}

string Shoes::get_type() {
    return this->_type;
}

string Shoes::get_brand() {
    return this->_brand;
}

string Shoes::get_color() {
    return this->_color;
}

int Shoes::get_size() {
    return this->_size;
}