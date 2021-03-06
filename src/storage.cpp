#include "storage.h"

Storage::Storage() {}

void Storage::add_product(shared_ptr<Product> product){    
    map<string, shared_ptr<Product>>::iterator i = this->_storage.find(product->_product_id);

    if (i != _storage.end()){
        i->second->update_quantity(product->get_quantity());
        return;
    }
    else {
        _storage.insert(pair<string, shared_ptr<Product>>(product->_product_id, product));
    }
}

map<string, shared_ptr<Product>>::iterator Storage::get_product_tuple (string product_id) {
    map<string, shared_ptr<Product>>::iterator i = this->_storage.find(product_id);
    return i;
}

shared_ptr<Product> Storage::get_product(string product_id) {
    map<string, shared_ptr<Product>>::iterator i = this->get_product_tuple(product_id);
    return i->second;
}

void Storage::remove_product(string product_id) {
    _storage.erase(this->get_product_tuple(product_id));
}

void Storage::list_products() const {
    map<shared_ptr<Product>, unsigned int>::iterator it;
    cout << "#############################" << endl
         << "########  PRODUTOS   ########" << endl
         << "#############################" << endl;

    for (auto& i : this->_storage) i.second->print();
    
    cout << "#############################" << endl
         << "######## End of list ########" << endl
         << "#############################" << endl;
}

void Storage::clear() {
    this->_storage.clear();
}