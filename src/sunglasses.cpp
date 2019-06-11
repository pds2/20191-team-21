#include "sunglasses.h"


//CONSTRUCTOR
Sunglasses::Sunglasses(string brand, string color, int quantity, double price) 
        : Product("Oculos ", std::move(brand), std::move(color), quantity, price){};

//SETTERS
void Sunglasses::set_type(string type) {
    this->_type = std::move(type);
}

void Sunglasses::set_brand(string brand) {
    this->_brand = std::move(brand);
}

void Sunglasses::set_color(string color) {
    this->_color = std::move(color);
}

void Sunglasses::set_price(double price){
    this->_price = price;
};

void Sunglasses::set_quantity(int quantity){
    this->_quantity = quantity;
};


//GETTERS
double Sunglasses::get_price(){
    return this->_price;
}

int Sunglasses::get_quantity(){
    return this->_quantity;
}

string Sunglasses::get_type() {
    return this->_type;
}

string Sunglasses::get_brand() {
    return this->_brand;
}

string Sunglasses::get_color() {
    return this->_color;
}
