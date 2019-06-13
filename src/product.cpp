#include <utility>

#include "product.h"

//CONSTRUCTOR
// Product::Product(double price, int quantity, string type, string color, string brand, string product_id){
Product::Product(double price, string type, string color, string brand, unsigned int quantity){
    string id = type + brand + color;
    transform(id.begin(), id.end(), id.begin(), ::toupper);
    this->_product_id = id;
    this->_price = price;
    this->_brand = std::move(brand);
    this->_color = std::move(color);
    this->_type = std::move(type);
    this->_quantity = std::move(quantity);
}

//SETTERS
void Product::set_type(string type) {
    this->_type = std::move(type);
}

void Product::set_brand(string brand) {
    this->_brand = std::move(brand);
}

void Product::set_color(string color) {
    this->_type = std::move(color);
}

void Product::set_price(double price){
    this->_price = price;
}

void Product::set_quantity(unsigned int quantity){
    this->_quantity = quantity;
}

void Product::update_quantity(unsigned int add){
    this->_quantity += add;
}
//GETTERS
double Product::get_price() const {
    return this->_price;
}

string Product::get_type() const {
    return this->_type;
}

string Product::get_brand() const {
    return this->_brand;
}

string Product::get_color() const {
    return this->_color;
}

unsigned int Product::get_quantity() const {
    return this->_quantity;
}

string Product::get_id() const {
    return this->_product_id;
}


//OPERATORS

bool Product::operator>(const Product &product) const {
    return (this->_product_id > product._product_id);
}
bool Product::operator>=(const Product &product) const {
    return (this->_product_id >= product._product_id);
}
bool Product::operator<(const Product &product) const {
    return (this->_product_id < product._product_id);
}
bool Product::operator<=(const Product &product) const {
    return (this->_product_id <= product._product_id);
}
bool Product::operator!=(const Product &product) const {
    return (this->_product_id != product._product_id);
}
bool Product::operator==(const Product &product) const {
    return (this->_product_id == product._product_id);
}
bool Product::equals(const Product &product) const {
    return (this->_product_id == product._product_id);
}

// void Product::print() const {
//         cout << "Produto: " << this->_type << endl
//         << "Marca: " << this->_brand << endl
//         << "Cor: " << this->_color << endl
//         << "Preço(R$): " << this->_price << endl;
// }