#include "shoes.h"


//CONSTRUCTOR
Shoes::Shoes(string type, string brand, string color, int size, int quantity, double price)
        : Product(std::move(type), std::move(brand), std::move(color), quantity, price) {
    this->_size = size;
}

//SETTERS
void Shoes::set_type(string type) {
    this->_type = std::move(type);
}


void Shoes::set_brand(string brand) {
    this->_brand = std::move(brand);
}


void Shoes::set_color(string color) {
    this->_color = std::move(color);
}


void Shoes::set_size(int size) {
    this->_size = size;
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
