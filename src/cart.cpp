#include "client.h"
#include "cart.h"


vector<Product> Cart::get_products() {
    return this->cart_products;
}


double Cart::get_total_price() {
    return this->_total_price;
}


void Cart::add_clothes(Clothes c_added, int quantity) {


}


void Cart::add_shoes(Shoes s_added, int quantity) {


}


void Cart::add_sunglasses(Sunglasses sg_added, int quantity) {


}


void Cart::remove_product() {


}


void Cart::cancel_purchase() {


}


void Cart::finish_purchase() {


}