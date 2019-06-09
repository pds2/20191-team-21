#include "sunglasses.h"


//CONSTRUCTOR
Sunglasses::Sunglasses(string type, string brand, string color, double price, int quantity)
        : Product(price, quantity, std::move(type), std::move(color), std::move(brand)){
    string id = type + brand + color;
    transform(id.begin(), id.end(), id.begin(), ::toupper);
    this->_product_id = id;
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

void Sunglasses::set_quantity(int quantity){
    this->_quantity = quantity;
};

void Sunglasses::set_size(int size){
    this->_size = size;
}


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

int Sunglasses::get_size() {
    return this->_size;
}

void Sunglasses::print() const {
    cout << "Produto: " << _type << endl
        << "ID: " << _product_id << endl
        << "Marca: " << _brand << endl
        << "Cor: " << _color << endl
        << "Tamanho: " << _size << endl
        << "Preço(R$): " << _price << endl;
}