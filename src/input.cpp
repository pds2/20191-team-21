#include "input.h"

shared_ptr<Product> Input::product(){
    map<string, string> features = Input::features();
    double price = Input::price();
    unsigned int quantity = Input::quantity();
    cout << endl;
    auto product = make_shared<Product>(features, price, quantity);
    return product;
}

map<string, string> Input::features(){
    map<string, string> features;
    vector<string> feature_list = FEATURE_LIST;
    string entry;

    for(auto const& f: feature_list) {
        cout << "Digite o(a) " << f << ":" << endl;
        getline (cin, entry);
        features[f] = entry;
    }
    return features;
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
