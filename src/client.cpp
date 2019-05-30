#include "client.h"


//Client::Client(string name, string login, string password) ao criar o cliente, criar um carrinho pra ele client_cart

//CONSTRUCTOR
Client::Client(string name, string login, string password) {
    this->_name = std::move(name);
    this->_login = std::move(login);
    this->_password = std::move(password);
}

//GETTERS
string Client::get_name(){
    return this->_name;
};
string Client::get_login(){
    return this->_login;
};
string Client::get_password(){
    return this->_password;
};


//METHODS
void Client::search_product() {

    ifstream clothes_strg, shoes_strg, sunglasses_strg;

    int product_option, add_or_not, category;
    int size_in_shoes, size_s;
    string type_in_file, brand_in_file, size_in_clothes, color_in_file;
    string type, brand, size_c, color;
    double price;
    int quantity_desired, quantity;

    bool product_menu_open = true;
    bool product_exists = false;
    bool product_found = false;

    while(product_menu_open) {

        cout << "Selecione a categoria do produto que voce deseja comprar"
             << endl << "1 - Roupa" << endl << "2 - Sapato" << endl <<
             "3 - Oculos de sol" << endl;
        cin >> category;
        cout << endl;

        switch(category) { //cada opcao mostra todos os produtos da categoria escolhida

            case 1:

                clothes_strg.open("storage-clothes.txt", ios::in);
                while(!clothes_strg.eof()) {

                    clothes_strg >> type_in_file >> brand_in_file >> color_in_file >> size_in_clothes >> quantity >> price;

                    cout << type_in_file << " " << brand_in_file << endl;
                    cout << "Cor: " << color_in_file << endl;
                    cout << "Tamanho: " << size_in_clothes << endl;
                    cout << "Preco: " << price << endl;
                    cout << "Quantidade disponivel: " << quantity << endl << endl;

                }
                clothes_strg.close();
                break;

            case 2:

                shoes_strg.open("storage-shoes.txt", ios::in);
                while(!shoes_strg.eof()) {

                    shoes_strg >> type_in_file >> brand_in_file >> color_in_file >> size_in_shoes >> quantity >> price;

                    cout << type_in_file << " " << brand_in_file << endl;
                    cout << "Cor: " << color_in_file << endl;
                    cout << "Tamanho: " << size_in_shoes << endl;
                    cout << "Preco: " << price << endl;
                    cout << "Quantidade disponivel: " << quantity << endl << endl;

                }
                shoes_strg.close();
                break;

            case 3:

                sunglasses_strg.open("storage-sunglasses.txt", ios::in);
                while(!sunglasses_strg.eof()) {

                    sunglasses_strg >> brand_in_file >> color_in_file >> quantity >> price;

                    cout << brand_in_file << endl;
                    cout << "Cor: " << color_in_file << endl;
                    cout << "Preco: " << price << endl;
                    cout << "Quantidade disponivel: " << quantity << endl << endl;

                }
                sunglasses_strg.close();
                break;

            default:
                cout << "Comando invalido" << endl;
                break;

        }

        cout << "--------------------" << endl;
        cout << "O que voce gostaria de fazer?" << endl <<
             "1 - Adicionar um produto ao carrinho" << endl <<
             "2 - Visualizar o carrinho" << endl << "3 - Voltar ao menu"
             << endl;
        cin >> add_or_not;
        cout << endl;

        switch(add_or_not) {

            case 1:
                cout << "Marca do produto: ";
                cin >> brand;
                cout << endl;

                clothes_strg.open("storage-clothes.txt");
                while(!clothes_strg.eof()) {
                    clothes_strg >> type_in_file >> brand_in_file >> color_in_file >> size_in_clothes >> quantity >> price;

                    if(brand_in_file == brand) {
                        cout << "Tipo do produto: ";
                        cin >> type;
                        if(type_in_file == type) {
                            cout << "Cor: ";
                            cin >> color;
                            if(color_in_file == color) {
                                cout << "Tamanho: ";
                                cin >> size_c;
                                if(size_in_clothes == size_c) {
                                    cout << "Encontramos seu produto!" << endl
                                         << type << " " << brand << " " << size_c << endl
                                         << price << " reais" << endl;
                                    product_exists = true;
                                    break;
                                }
                            }
                        }
                    }
                }
                clothes_strg.close();

                if(!product_found) {
                    cout << endl << "Procurando..." << endl;

                    shoes_strg.open("storage-shoes.txt");
                    while(!shoes_strg.eof()) {
                        shoes_strg >> type_in_file >> brand_in_file >> size_in_shoes >> quantity >> price;

                        if(brand_in_file == brand) {
                            cout << "Tipo do produto: ";
                            cin >> type;
                            if(type_in_file == type) {
                                cout << "Cor: ";
                                cin >> color;
                                if(color_in_file == color) {
                                    cout << "Tamanho: ";
                                    cin >> size_s;
                                    if(size_in_shoes == size_s) {
                                        cout << "Encontramos seu produto!" << endl
                                             << type << " " << brand << " " << size_s << endl
                                             << price << " reais" << endl;
                                        product_exists = true;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    shoes_strg.close();

                    cout << endl << "Procurando..." << endl;

                    sunglasses_strg.open("storage-sunglasses.txt");
                    while(!sunglasses_strg.eof()) {
                        sunglasses_strg >> brand_in_file >> quantity >> price;

                        if(brand_in_file == brand) {
                            cout << "Cor: ";
                            cin >> color;
                            if(color_in_file == color) {
                                cout << "Encontramos seu produto!" << endl
                                     << brand << endl << price << " reais" << endl;
                                product_exists = true;
                                break;
                            }
                        }
                    }
                    sunglasses_strg.close();
                }

                if(!product_exists)
                    cout << "Esse produto nao existe" << endl << endl;
                else {
                    bool close_panel = false;
                    bool quantity_exists = false;

                    while(!close_panel) {
                        cout << "--------------------" << endl;
                        cout << "1 - Confirmar o produto escolhido" << endl
                             << "2 - Escolher outro produto" << endl <<
                             "3 - Cancelar e ver carrinho" << endl <<
                             "4 - Voltar" << endl;
                        cin >> product_option;
                        cout << endl;

                        switch(product_option) {

                            case 1:

                                while(!quantity_exists) {

                                    cout << "Quantas unidades deseja adicionar? ";
                                    cin >> quantity_desired;
                                    cout << endl;

                                    if(quantity_desired > quantity) {
                                        cout << "Temos " << quantity << " unidades desse produto"
                                             << endl << endl;
                                    }
                                    else {
                                        if(category == 1) {

                                            Clothes added(0, type, brand, color, size_c, price, quantity);
                                            client_cart.add_clothes(added, quantity_desired);
                                            quantity_exists = true;
                                            close_panel = true;

                                        }
                                        else if(category == 2) {

                                            Shoes added(type, brand, color, size_s, price, quantity);
                                            client_cart.add_shoes(added, quantity_desired);
                                            quantity_exists = true;
                                            close_panel = true;

                                        }
                                        else if(category == 3) {

                                            Sunglasses added(brand, color, price, quantity);
                                            client_cart.add_sunglasses(added, quantity_desired);
                                            quantity_exists = true;
                                            close_panel = true;

                                        }
                                    }
                                }
                                break;

                            case 2:
                                close_panel = true;
                                break;

                            case 3:
                                see_cart();
                                close_panel = true;
                                break;

                            case 4:
                                close_panel = true;
                                break;

                            default:
                                cout << "Comando invalido" << endl << endl;
                                break;

                        }
                    }

                }

            case 2:
                see_cart();
                product_menu_open = false;
                break;

            case 3:
                product_menu_open = false;
                break;

            default:
                cout << "Comando invalido" << endl << endl;

        }
    }
}


void Client::see_cart() {


}