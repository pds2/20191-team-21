#include "product.h"


//CONSTRUCTOR
// Product::Product(double price, int quantity, string type, string color, string brand, string product_id){
Product::Product(map<string, string> features, double price, unsigned int quantity){
    this->_features.clear();
    this->_features = features;
    this->_price = price;
    this->_quantity = quantity;
    this->_product_id = IdMaker::make_id(features);
}
Product::Product(){ }

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

shared_ptr<Product> Product::read_from(istream &in){
    map<string, string> features;
    vector<string> feature_list = FEATURE_LIST;
    string feature_key;
    string feature_value;

    unsigned int quantity;
    double price;

    for(auto const& f: feature_list) {
        //cabe um exception com f.first
        in >> feature_key;
        in >> feature_value;
        features[feature_key] = feature_value;
    }
    in >> quantity;
    in >> price;
    auto product = make_shared<Product>(features, price, quantity);
    return product;
}

void Product::save_to(std::ostream &out) {
    for(auto const& f: this->_features) {
        out << f.first << endl;
        out << f.second;
        out << endl;
    }
//    out << endl;
    out << this->get_price() << endl;
    out << this->get_quantity() << endl;
}

void Product::print() const {
    cout << "---" << endl;
    for (auto const& i : _features) {
        cout  << i.first
              << " : " 
              << i.second
              << endl;
    }
    cout << "Preço: $" << this->_price << endl
         << "Qtd em estoque: " << this->_quantity << endl;
}
