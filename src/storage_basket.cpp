#include "storage_basket.h"

Basket::Basket(){

}

void Basket::calculate_total_price(){
    _total_price = 0.0;
    for (auto& i : _storage) {
        _total_price += i.second->get_price();
    }
}