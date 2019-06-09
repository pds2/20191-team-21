#include <utility>

#include "clothes.h"


//CONSTRUCTOR
Clothes::Clothes(string type, string brand, string color, string size, double price, int quantity)
        : Product(price, quantity, std::move(type), std::move(color), std::move(brand)) {
    this->_size = std::move(size);
    string id = type + brand + color + size;
    transform(id.begin(), id.end(), id.begin(), ::toupper);
    this->_product_id = id;
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

void Clothes::print() const{
    cout << "Produto: " << _type << endl
        << "ID: " << _product_id << endl
        << "Marca: " << _brand << endl
        << "Cor: " << _color << endl
        << "Tamanho: " << _size << endl
        << "Preço(R$): " << _price << endl;
}