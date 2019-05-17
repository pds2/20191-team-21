#ifndef SUNGLASSES_H_PDS
#define SUNGLASSES_H_PDS

#include "product.h"

class Sunglasses : public Product {

  string _brand;
  string _color;

  public:    
    Sunglasses(string brand, string color, double price, int quantity);

    virtual void set_brand(string brand);
    virtual void set_color(string color);

    virtual string get_brand();    
    virtual string get_color();

};

#endif