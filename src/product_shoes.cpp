#include "product_shoes.h"


//CONSTRUCTOR
Shoes::Shoes(string type, string brand, string color, int size, double price, unsigned int quantity)
        : Product(price, std::move(type), std::move(color), std::move(brand), move(quantity)) {
            this->_product_id = ID_SHOES + this->_product_id + to_string(size);

}

//SETTERS
void Shoes::set_size(int size) {
    this->_size = size;
}

//GETTERS
int Shoes::get_size() {
    return this->_size;
}

// OPERATORS
bool Shoes::operator<(const Shoes &shoes) const {
    return (this->_product_id < shoes._product_id);
}

void Shoes::print() const {
    cout << "--------------------------------------------" << endl
        << "Produto: " << this->_type << endl
        << "ID: " << this->_product_id << endl
        << "Marca: " << this->_brand << endl
        << "Cor: " << this->_color << endl
        << "Tamanho: " << this->_size << endl
        << "Preço(R$): " << this->_price << endl
        << "Qtd em estoque: " << this->_quantity << endl;
}