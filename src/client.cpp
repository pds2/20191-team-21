#include "client.h"

//CONSTRUCTOR
Client::Client(string name, string login, string password) : User(std::move(name), std::move(login), std::move(password))
{}

//GETTERS
string Client::get_name(){
    return this->_name;
}
string Client::get_login(){
    return this->_login;
}
string Client::get_password(){
    return this->_password;
}

//MAP FUNCTIONS
void Client::add_product (const shared_ptr<Product> product, unsigned int quantity){
    
    map<shared_ptr<Product>, unsigned int>::iterator it = cart.find(product);
    
    if (it != cart.end()){
        it->second += quantity;
        return;
    }
    else {
        cart.insert(pair<shared_ptr<Product>, unsigned int>(product, quantity));
    }
}

//NEED ERROR HANDLING!!
void Client::remove_product (const shared_ptr<Product> product, unsigned int quantity){
    map<shared_ptr<Product>, unsigned int>::iterator it = cart.find(product);

    if (it != cart.end()){
        it->second -= quantity;
        if (it->second > 0){
            return;
        }
    }
    cart.erase(it); 

}
void Client::list_products(){
    map<shared_ptr<Product>, unsigned int>::iterator it;

    cout << "Seu Carrinho" << endl;
    for (auto& i : cart) i.first->print();
}

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

      int aux = 0;

      switch(add_or_not) {

        case 1:
          switch(category) {

            case 1:
              cout << "Marca do produto: ";
              cin >> brand;
              cout << "Tipo do produto: ";
              cin >> type;
              cout << "Cor: ";
              cin >> color;
              cout << "Tamanho: ";
              cin >> size_c;

              clothes_strg.open("storage-clothes.txt");
              while(!clothes_strg.eof()) {
                clothes_strg >> type_in_file >> brand_in_file >> color_in_file >> size_in_clothes >> quantity >> price;

                if(brand_in_file == brand) {
                  if(type_in_file == type) {
                    if(color_in_file == color) {
                      if(size_in_clothes == size_c) {
                        cout << "Encontramos seu produto!" << endl << endl
                            << type << " " << brand << " " << color << " " << size_c
                            << endl << price << " reais" << endl << endl;
                        aux = 0;
                        product_exists = true;
                        break;
                      }
                      else aux++;
                    }
                    else aux++;
                  }
                  else aux++;
                }
                else aux++;
              }
              clothes_strg.close();

              if(aux != 0)
                cout << endl << "Esse produto nao existe no estoque" << endl;
              break;

              case 2:
                cout << "Marca do produto: ";
                cin >> brand;
                cout << "Tipo do produto: ";
                cin >> type;
                cout << "Cor: ";
                cin >> color;
                cout << "Tamanho: ";
                cin >> size_s;

                shoes_strg.open("storage-shoes.txt");
                while(!shoes_strg.eof()) {
                  shoes_strg >> type_in_file >> brand_in_file >> size_in_shoes >> quantity >> price;

                  if(brand_in_file == brand) {
                    if(type_in_file == type) {
                      if(color_in_file == color) {
                        if(size_in_shoes == size_s) {
                          cout << "Encontramos seu produto!" << endl << endl
                              << type << " " << brand << " " << color << " " << size_s
                              << endl << price << " reais" << endl << endl;
                          aux = 0;
                          product_exists = true;
                          break;
                        }
                        else aux++;
                      }
                      else aux++;
                    }
                    else aux++;
                  }
                  else aux++;
                }
                shoes_strg.close();

                if(aux != 0)
                cout << endl << "Esse produto nao existe no estoque" << endl;
                break;

                case 3:
                  cout << "Marca do produto: ";
                  cin >> brand;
                  cout << "Cor: ";
                  cin >> color;

                  sunglasses_strg.open("storage-sunglasses.txt");
                  while(!sunglasses_strg.eof()) {
                    sunglasses_strg >> brand_in_file >> quantity >> price;

                    if(brand_in_file == brand) {
                      if(color_in_file == color) {
                        cout << "Encontramos seu produto!" << endl << endl
                            << brand << " " << color << endl
                            << price << " reais" << endl << endl;
                        aux = 0;
                        product_exists = true;
                        break;
                      }
                      else aux++;
                    }
                    else aux++;
                  }
                  sunglasses_strg.close();

                  if(aux != 0)
                    cout << endl << "Esse produto nao existe no estoque" << endl;
                  break;
              }

              if(product_exists) {
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
                          Clothes added(type, brand, color, size_c, price, quantity);
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
                          Sunglasses added(type, brand, color, price, quantity);
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
