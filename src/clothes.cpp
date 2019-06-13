#include <utility>

#include "clothes.h"


//CONSTRUCTOR
Clothes::Clothes(string type, string brand, string color, string size, double price, unsigned int quantity)
        : Product(price, move(type), move(color), move(brand), move(quantity)) {
            transform(size.begin(), size.end(), size.begin(), ::toupper);
            this->_product_id = ID_CLOTHES + this->_product_id + size;
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


//GETTERS
double Clothes::get_price(){
    return this->_price;
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

// OPERATORS
bool Clothes::operator<(const Clothes &clothes) const {
    return (this->_product_id < clothes._product_id);
}

void Clothes::print() const{
    cout << "Produto: " << _type << endl
        << "ID: " << _product_id << endl
        << "Marca: " << _brand << endl
        << "Cor: " << _color << endl
        << "Tamanho: " << _size << endl
        << "Preço(R$): " << _price << endl;
}