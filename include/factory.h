#ifndef FACTORY_H_PDS
#define FACTORY_H_PDS

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <utility>

#include "product.h"

#define FEATURES_LIST { "type", "brand", "model", "color", "size" }

using namespace std;

class Factory {
private:
    static map<string, string> input_features();
    static double input_price();
    static unsigned int input_quantity();

public:
    static Product make_product();
};

#endif //FACTORY_H_PDS
