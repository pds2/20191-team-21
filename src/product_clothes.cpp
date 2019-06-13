#include <utility>

#include "product_clothes.h"


//CONSTRUCTOR
Clothes::Clothes(string type, string brand, string color, string size, double price, unsigned int quantity)
        : Product(price, move(type), move(color), move(brand), move(quantity)) {
            transform(size.begin(), size.end(), size.begin(), ::toupper);
            this->_product_id = ID_CLOTHES + this->_product_id + size;
}

//SETTERS
void Clothes::set_size(string size) {
    this->_size = std::move(size);
}

//GETTERS
string Clothes::get_size() const{
    return this->_size;
}

// OPERATORS
bool Clothes::operator<(const Clothes &clothes) const {
    return (this->_product_id < clothes._product_id);
}

void Clothes::print() const{
    cout << "--------------------------------------------" << endl
        << "Produto: " << this->_type << endl
        << "ID: " << this->_product_id << endl
        << "Marca: " << this->_brand << endl
        << "Cor: " << this->_color << endl
        << "Tamanho: " << this->_size << endl
        << "Preço(R$): " << this->_price << endl
        << "Qtd em estoque: " << this->_quantity << endl;
}