#include "shoes.h"


//CONSTRUCTOR
Shoes::Shoes(string type, string brand, string color, int size, double price, int quantity)
        : Product(price, quantity, std::move(type), std::move(color), std::move(brand)) {
    this->_size = size;
    
    stringstream ss;
    ss << size;
    string id = type + brand + color + ss.str();
    transform(id.begin(), id.end(), id.begin(), ::toupper);
    this->_product_id = id;
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

void Shoes::print() const{
    cout << "Produto: " << _type << endl
        << "ID: " << _product_id << endl
        << "Marca: " << _brand << endl
        << "Cor: " << _color << endl
        << "Tamanho: " << _size << endl
        << "Preço(R$): " << _price << endl;
}