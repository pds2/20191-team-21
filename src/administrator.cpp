#include <utility>
#include "administrator.h"

//CONSTRUCTOR
Admin::Admin(string name, string login, string password) : User(std::move(name), std::move(login), std::move(password))
    {};

//GETTERS
string Admin::get_name(){
    return this->_name;
};
string Admin::get_login(){
    return this->_login;
};
string Admin::get_password(){
    return this->_password;
};


//ATTRIBUTES
void Admin::add_product_warehouse() {
    int category;

    double price;
    unsigned int quantity;
    string color;
    string brand;

    string str_size;
    unsigned int int_size;

    while(true){
        // NEED ERROR CATCHING
        cout << endl << "----------" << endl
             << "Selecione a categoria do produto que voce deseja adicionar:" << endl
             << "1 - Roupa" << endl
             << "2 - Sapato" << endl
             << "3 - Oculos de sol" << endl
             << "Digite 0 para voltar" << endl;
        cin >> category;
	    cout << endl;

        if (category == 0){
            return;
        }

        cout << endl
             << "Inserindo novo produto...";
        cout << endl
             << "Digite a marca:" << endl;
        cin >> brand;
        cout << endl;

        cout << "Digite a cor:" << endl;
        cin >> color;
        cout << endl;

        cout << "Digite o preço:" << endl;
        cin >> price;
        cout << endl;

        cout << "Digite a quantidade de produtos a ser adicionada:" << endl;
        cin >> quantity;
        cout << endl;

        if (category != 3){
            cout << "Digite o tamanho:" << endl;
            if (category == 2){
                cin >> int_size;
                cout << endl;
            }
            else {
                cin >> str_size;
                cout << endl;
            }    
        }

        switch(category){
            case 1:
                warehouse.add_product((Clothes("clothes", brand, color, str_size, price)), quantity);
            case 2:
                warehouse.add_product((Shoes("shoes", brand, color, int_size, price)), quantity);
            case 3:
                warehouse.add_product((Sunglasses("sunglasses", brand, color, price)), quantity);

        }
    }
}


void Admin::change_product_quantity() {

//arquivo

}


void Admin::change_product_price() {

//arquivo

}


void Admin::remove_product() {

//arquivo

}

void Admin::show_storage() {

//arquivo

}