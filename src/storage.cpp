#include "storage.h"

Storage::Storage() {}


// Storage::Storage(string file_address) {}


void Storage::add_product(string product_id, shared_ptr<Product> product){
    map<string, shared_ptr<Product>>::iterator i = _storage.find(product_id);

    if (i != _storage.end()){
        _storage[product_id]->update_quantity(product->get_quantity);
        return;
    }
    else {
        _storage.insert(pair<string, shared_ptr<Product>>(product_id, product));
    }
}

void Storage::remove_product(map<string, shared_ptr<Product>>::iterator product_tuple) {
    _storage.erase(product_tuple);
}

void Storage::remove_product(string product_id) {
    shared_ptr<Product> p = Storage::get_product (product_id);
    map<string, shared_ptr<Product>>::iterator  i = Storage::find_tuple(p);

    _storage.erase(i);
}

map<string, shared_ptr<Product>>::iterator Storage::find_tuple (const shared_ptr<Product> product) const {
    for (auto& i : _storage) {
        if (i.second == product){
            break;
        }
    }
    return i;
}