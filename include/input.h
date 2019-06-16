#ifndef INPUT_H_PDS
#define INPUT_H_PDS

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <utility>
#include <memory>

#include "product.h"

#define FEATURES_LIST { "type", "brand", "model", "color", "size" }

using namespace std;

class Input {
public:
    static shared_ptr<Product> product();
    static map<string, string> features();
    static double price();
    static unsigned int quantity();
    static string product_id();

};

#endif //INPUT_H_PDS
