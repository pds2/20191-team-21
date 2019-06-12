#include "warehouse.h"

void Warehouse (){

}
void Warehouse::add_product(Clothes clothes, unsigned int quantity){
    map<Clothes, unsigned int>::iterator i = this->_clothes.find(clothes);
    if(i != _clothes.end())
    {
       i->second += quantity;
    }
    else {
        this->_clothes.insert(pair<Clothes, unsigned int>(clothes, quantity));
    }
}

void Warehouse::add_product(Shoes shoes, unsigned int quantity){
    map<Shoes, unsigned int>::iterator i = this->_shoes.find(shoes);
    if(i != _shoes.end())
    {
       i->second += quantity;
    }
    else {
        this->_shoes.insert(pair<Shoes, unsigned int>(shoes, quantity));
    }
}
void Warehouse::add_product(Sunglasses sunglasses, unsigned int quantity){
    map<Sunglasses, unsigned int>::iterator i = this->_sunglasses.find(sunglasses);
    if(i != _sunglasses.end())
    {
       i->second += quantity;
    }
    else {
        this->_sunglasses.insert(pair<Sunglasses, unsigned int>(sunglasses, quantity));
    }
}
void Warehouse::delete_product(string product){
    if (product.substr(0, 3) == ID_CLOTHES){
        Warehouse::delete_clothes(product);
    }
    else if (product.substr(0, 3) == ID_SHOES){
        Warehouse::delete_shoes(product);
    }
    else if (product.substr(0, 3) == ID_SUNGLASSES){
        Warehouse::delete_sunglasses(product);
    }
    else {
        cout << endl << "Chave inválida! Valor inserido: " << product << endl;
    }
}

void Warehouse::delete_clothes(string product){
    
}
void Warehouse::delete_shoes(string product)
void Warehouse::delete_sunglasses(string product)

void Warehouse::delete_product(Clothes clothes){

}
void Warehouse::delete_product(Shoes shoes){

}
void Warehouse::delete_product(Sunglasses sunglasses){

}
void Warehouse::list_products(){
    Warehouse::list_shoes();
    Warehouse::list_clothes();
    Warehouse::list_sunglasses();
}
void Warehouse::list_products(string type){
    
}

void Warehouse::list_shoes(){
    cout << endl << "Lista de Sapatos: " << endl;
    for (auto const& i : this->_shoes){
        i.first.print();
        cout << "# Quantidade em estoque: " << i.second << endl << "---" << endl;
    }
}
void Warehouse::list_clothes(){
    cout << endl << "Lista de Roupas: " << endl;
    for (auto const& i : this->_clothes){
        i.first.print();
        cout << "# Quantidade em estoque: " << i.second << endl << "---" << endl;
    }
}
void Warehouse::list_sunglasses(){
    cout << endl << "Lista de Óculos: " << endl;
    for (auto const& i : this->_sunglasses){
        i.first.print();
        cout << "# Quantidade em estoque: " << i.second << endl << "---" << endl;
    }
}