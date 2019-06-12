#include "sunglasses.h"


//CONSTRUCTOR
Sunglasses::Sunglasses(string type, string brand, string color, double price)
        : Product(price, std::move(type), std::move(color), std::move(brand)){
            this->_product_id += to_string(this->_size);
};

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

void Sunglasses::set_size(int size){
    this->_size = size;
}


//GETTERS
double Sunglasses::get_price(){
    return this->_price;
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

int Sunglasses::get_size() {
    return this->_size;
}

// OPERATORS
bool Sunglasses::operator<(const Sunglasses &sunglasses) const {
    return (this->_product_id < sunglasses._product_id);
}

void Sunglasses::print() const {
    cout << "Produto: " << _type << endl
        << "ID: " << _product_id << endl
        << "Marca: " << _brand << endl
        << "Cor: " << _color << endl
        << "Tamanho: " << "ÚNICO" << endl
        << "Preço(R$): " << _price << endl;
}