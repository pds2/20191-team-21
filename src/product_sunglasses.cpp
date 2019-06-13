#include "product_sunglasses.h"


//CONSTRUCTOR
Sunglasses::Sunglasses(string type, string brand, string color, double price, unsigned int quantity)
        : Product(price, std::move(type), std::move(color), std::move(brand), move(quantity)){
            this->_product_id = ID_SUNGLASSES + this->_product_id + to_string(this->_size);
}

//SETTERS
void Sunglasses::set_size(int size){
    this->_size = size;
}

int Sunglasses::get_size() {
    return this->_size;
}

// OPERATORS
bool Sunglasses::operator<(const Sunglasses &sunglasses) const {
    return (this->_product_id < sunglasses._product_id);
}

void Sunglasses::print() const {
    cout << "--------------------------------------------" << endl
        << "Produto: " << this->_type << endl
        << "ID: " << this->_product_id << endl
        << "Marca: " << this->_brand << endl
        << "Cor: " << this->_color << endl
        << "Tamanho: " << "ÚNICO" << endl
        << "Preço(R$): " << this->_price << endl
        << "Qtd em estoque: " << this->_quantity << endl;
}