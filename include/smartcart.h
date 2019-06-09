#ifndef SMART_CART_H_PDS
#define SMART_CART_H_PDS

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class SmartCart {
public:
//CONSTRUCTOR
    SmartCart(double price, int _quantity, string type, string color, string brand);

//SETTERS
    void set_price(double price);

//GETTERS
    double get_price();

};

#endif //SMART_CART_H_PDS
