#ifndef ACTIONS_H_PDS
#define ACTIONS_H_PDS

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <utility>

#include "product.h"
#include "input.h"
#include "storage_basket.h"
#include "storage_warehouse.h"
#include "input.h"

using namespace std;

class Actions {
public:
    static void make_product();
    static void remove_product();
    static void add_product();


};

#endif //ACTIONS_H_PDS
