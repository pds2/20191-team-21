#include "input.h"

shared_ptr<Product> Input::product(){
    auto product = make_shared<Product>(features(), price(), quantity());
    return product;
}

map<string, string> Input::features(){
    map<string, string> p;
    vector<string> _feature_list = FEATURES_LIST;
    for(auto const& i: _feature_list) {
        string entry;
        cout << i << ":" << endl;
        while (getline (cin, entry));
        p.insert(pair<string, string>(i, entry));
    }
    return p;
}

double Input::price(){
    double price;
    cout << "Digite o preço:" << endl;
    cin >> price;
    return price;
}

unsigned int Input::quantity(){
    double quantity;
    cout << "Digite a quantidade:" << endl;
    cin >> quantity;
    return quantity;
}

string Input::product_id(){
    string p_id;
    cout << "Digite o ID do produto:" << endl;
    while (getline (cin, p_id));
    return p_id;
}
