#include "storage_basket.h"

Basket::Basket()
        : Storage() {}

double Basket::get_total_price() const {
    double total_price = 0.0;
    for (auto& i : _storage) {
        total_price += i.second->get_price()*i.second->get_quantity();
    }
    return total_price;
}

void Basket::view_basket() const {
    this->list_products();
    cout << "$$$$$$$$$$$$$$$$$$ TOTAL: " << this->get_total_price();
}
