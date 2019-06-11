#include <utility>

#include "clothes.h"


//CONSTRUCTOR
Clothes::Clothes(string type, string brand, string color, string size, int quantity, double price)
        : Product(std::move(type), std::move(brand), std::move(color), quantity, price) {
    this->_size = std::move(size);
}

//SETTERS
void Clothes::set_type(string type) {
    this->_type = std::move(type);
}


void Clothes::set_brand(string brand) {
    this->_brand = std::move(brand);
}


void Clothes::set_color(string color) {
    this->_color = std::move(color);
}


void Clothes::set_size(string size) {
    this->_size = std::move(size);
}

void Clothes::set_price(double price){
    this->_price = price;
};
void Clothes::set_quantity(int quantity){
    this->_quantity = quantity;
};


//GETTERS
double Clothes::get_price(){
    return this->_price;
}

int Clothes::get_quantity(){
    return this->_quantity;
}

string Clothes::get_type() {
    return this->_type;
}

string Clothes::get_brand() {
    return this->_brand;
}

string Clothes::get_color() {
    return this->_color;
}

string Clothes::get_size() {
    return this->_size;
}
