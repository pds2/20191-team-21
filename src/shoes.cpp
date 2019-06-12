#include "shoes.h"


//CONSTRUCTOR
Shoes::Shoes(string type, string brand, string color, int size, double price)
        : Product(price, std::move(type), std::move(color), std::move(brand)) {
            this->_product_id += to_string(size);
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


//GETTERS
double Shoes::get_price(){
    return this->_price;
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

// OPERATORS
bool Shoes::operator<(const Shoes &shoes) const {
    return (this->_product_id < shoes._product_id);
}

void Shoes::print() const {
    cout << "Produto: " << _type << endl
        << "ID: " << _product_id << endl
        << "Marca: " << _brand << endl
        << "Cor: " << _color << endl
        << "Tamanho: " << _size << endl
        << "Preço(R$): " << _price << endl;
}