#include "factory.h"

Product Factory::make_product(){
    cout << endl << "Entre com os dados do produto:" << endl;
    return Product(input_features(), input_price(), input_quantity());
}

static map<string, string> input_features(){
    map<string, string> fresh_product;
    vector<string> _feature_list = FEATURES_LIST;
    for(auto const& i: _feature_list) {
        string entry;
        cout << i << ":" << endl;
        while (getline (cin, entry));
        fresh_product.insert(pair<string, string>(i, entry));
    }
    return fresh_product;
}

static double input_price(){
    double price;
    cout << "Price:" << endl;
    cin >> price;
    return price;
}

static unsigned int input_quantity(){
    double quantity;
    cout << "Quantity:" << endl;
    cin >> quantity;
    return quantity;
}