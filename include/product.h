#ifndef PRODUCT_H_PDS
#define PRODUCT_H_PDS

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Product {

  double _price;
  int _quantity;

  public:

    Product(double price);

    void set_price(double price);
    void set_quantity(int quantity);
    virtual void set_type(string type);
    virtual void set_color(string color);
    virtual void set_brand(string brand);

    double get_price();
    int get_qantity();
    virtual string get_type();
    virtual string get_color();
    virtual string get_brand();

};

#endif