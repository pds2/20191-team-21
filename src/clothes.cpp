#include <utility>

#include "clothes.h"


//Clothes::Clothes(string type, string brand, string color, string size, double price)

//CONSTRUCTOR
Clothes::Clothes(string type, string brand, string color, string size, double price, int quantity)
        : Product(price, quantity, std::move(type), std::move(color), std::move(brand)) {
    this->_size = std::move(size);
}

//SETTERS
void Clothes::set_type(string type) {
    this->_type = std::move(type);
}


void Clothes::set_brand(string brand) {
    this->_type = std::move(brand);
}


void Clothes::set_color(string color) {
    this->_type = std::move(color);
}


void Clothes::set_size(string size) {
    this->_type = std::move(size);
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