#ifndef CLOTHES_H_PDS
#define CLOTHES_H_PDS

#include "product.h"

class Clothes : public Product {

  string _type;
  string _brand;
  string _color;
  string _size;

  public:
    Clothes(string type, string brand, string color, string size, double price, int quantity);

    virtual void set_type(string type);
    virtual void set_brand(string brand);
    virtual void set_color(string color);
    virtual void set_size(string size);

    virtual string get_type();
    virtual string get_brand();
    virtual string get_color();
    string get_size();

};

#endif
