#include <utility>

#include "product.h"

//CONSTRUCTOR
// Product::Product(double price, int quantity, string type, string color, string brand, string product_id){
Product::Product(map<string, string> features, double price, unsigned int quantity){
    this->_features = features;
    this->_price = price;
    this->_quantity = quantity;
    this->_product_id = Product::generate_id(features);
}

string Product::generate_id(map<string, string> features){
    string key;
    for (const auto& i : features){
        key += i.second;
    }
    transform(key.begin(), key.end(), key.begin(), ::toupper);
    return key;
}

//SETTERS
void Product::set_feature(string feature, string value){
    this->_features[feature] = value;
}

void Product::set_price(double price){
    this->_price = price;
}

void Product::set_quantity(unsigned int quantity){
    this->_quantity += quantity;
}

void Product::update_quantity(unsigned int add){
    this->_quantity += add;
}

//GETTERS
string Product::get_feature(string feature){
    return this->_features[feature];
}

double Product::get_price() const{
    return this->_price;
}
unsigned int Product::get_quantity() const{
    return this->_quantity;
}
string Product::get_id() const{
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

void Product::print() const {
    cout << "---" << endl;
    for (auto const& i : _features) {
        cout  << i.first
              << ' : ' 
              << i.second
              << endl;
    }
}