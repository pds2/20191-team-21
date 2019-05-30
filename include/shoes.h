#ifndef SHOES_H_PDS
#define SHOES_H_PDS

#include "product.h"

class Shoes : public Product {

  string _type;
  string _brand;
  string _color;
  int _size;

  public:
    Shoes(string type, string brand, string color, int size, double price, int quantity);

    virtual void set_type(string type);
    virtual void set_brand(string brand);
    virtual void set_color(string color);
    virtual void set_size(int size);

    virtual string get_type();
    virtual string get_brand();
    virtual string get_color();
    int get_size();

};

#endif
