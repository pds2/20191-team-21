#include "terminal.h"
#include <iostream>
#include <string.h>
#include <utility>
#include <stdio.h>

//User Terminal::_user;
Basket Terminal::_basket;
Warehouse Terminal::_warehouse;

Terminal::Terminal(){

    Terminal::_warehouse.read_from_db();
    this->_user = User("Salem", "salem666", "passwd", false);


    Terminal::_admin_commands.emplace("help", Terminal::c_print_help);
    Terminal::_admin_commands.emplace("list products", Terminal::c_list_products);
    Terminal::_admin_commands.emplace("create product", Terminal::c_create_product);
    Terminal::_admin_commands.emplace("warehouse remove product", Terminal::c_rm_product_warehouse);
    Terminal::_admin_commands.emplace("warehouse clear", Terminal::c_clear_warehouse);
 
    Terminal::_client_commands.emplace("view products", Terminal::c_list_products);
    Terminal::_client_commands.emplace("basket add_product", Terminal::c_add_product_basket);
    Terminal::_client_commands.emplace("basket remove_product", Terminal::c_rm_product_basket);
    Terminal::_client_commands.emplace("basket view", Terminal::c_view_basket);
    Terminal::_client_commands.emplace("basket checkout", Terminal::c_checkout_basket);
    Terminal::_client_commands.emplace("basket clear", Terminal::c_clear_basket);
    Terminal::_admin_commands.emplace("warehouse save", Terminal::c_save_warehouse);

}

void Terminal::menu_home(){
    bool first_run = true;
    while(true){        
        if(first_run){
            first_run = false;
            Terminal::print_greetings();
            string pass;
            cout << "Se você for admin, entre com sua chave:" << endl;
            
            getline(cin,pass);
            if (strcmp(pass.c_str(), ADMIN_KEY) == 0){            
                _user.set_admin(true);
                cout << "Logged as admin!" << endl;
            } else {
                cout << "Invalid key provided, logged as client!" << endl;
                _user.set_admin(false);
            }
        }
        string cmd;
        cout << endl << "Press Enter to continue" << endl;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << endl << "|||||||||||||||||||Screen Divider|||||||||||||||||||" << endl << endl
             << "Digite um comando (help para a lista de opcoes): " << endl;
        getline(cin,cmd);
        if (strcmp(cmd.c_str(), "exit") == 0){
            return;
        }
        if (cmd.size() > 3){
            if (this->_user.is_admin()){
                Terminal::_admin_commands[cmd]();
            }
            else {
                Terminal::_client_commands[cmd]();
            }
        }
    }
}

void Terminal::print_greetings() const {
    cout << endl
       << "  (¯`·.¸¸.·´¯`·.¸¸.·´¯)            /\\-/\\                   " << endl
       << "  ( \\                 / )         /a a  \\               _  " << endl
       << " ( \\ )               ( / )       =\\ Y  =/-~~~~~~-,_____/ ) " << endl
       << "( ) (  Salem's Shop  ) ( )         '^--'          ______/  " << endl
       << " ( / )               ( \\ )          \\           /         " << endl
       << "  ( /                 \\ )           ||  |---'\\  \\         " << endl
       << "   (_.·´¯`·.¸¸.·´¯`·.¸_)            (_(__|   ((__|         " << endl
       << "(Arte precisa de um terminal monospace para sair corretamente)" << endl;
}
//general
void Terminal::c_print_help(){
    cout << ">" << endl
         << "Lista de comandos:" << endl << endl
         << "help" << "                     -> " << "Lista comandos de ajuda" << endl << endl
         << "list products" << "            -> " << "Lista os produtos em estoque" << endl << endl
         << "create product" << "           -> " << "Adiciona produto da base de dados" << endl << endl
         << "warehouse remove product" << " -> " << "Remove produto da base de dados" << endl << endl
         << "warehouse clear" << "          -> " << "Limpa a base de dados" << endl << endl
         << "warehouse save" << "           -> " << "Salva a base de dados em arquivo" << endl << endl
         << "basket add product" << "       -> " << "Adiciona produto a cesta de compras" << endl << endl
         << "basket remove product" << "    -> " << "Remove produto da cesta de compras" << endl << endl
         << "basket view" << "              -> " << "Lista produtos na cesta de compras" << endl << endl
         << "basket checkout" << "          -> " << "Finaliza compra" << endl << endl
         << "basket clear" << "             -> " << "Limpa cesta de compras" << endl << endl;
}
void Terminal::c_list_products(){
    Terminal::_warehouse.list_products();
}
void Terminal::c_save_warehouse(){
    Terminal::_warehouse.save_to_db();
}
//admin
void Terminal::c_create_product(){
    cout << endl << "Adicionando produto:" << endl;
    Terminal::_warehouse.add_product(Input::product());
}
void Terminal::c_rm_product_warehouse(){
    Terminal::_warehouse.remove_product(Input::product_id());
}

void Terminal::c_clear_warehouse(){
    Terminal::_warehouse.clear();
}
//client
void Terminal::c_add_product_basket(){
    Terminal::_basket.add_product(_warehouse.get_product(Input::product_id()));
}
void Terminal::c_rm_product_basket(){
    Terminal::_basket.remove_product(Input::product_id());

}
void Terminal::c_view_basket(){
    Terminal::_basket.view_basket();
}
void Terminal::c_checkout_basket(){
//    for (auto& i : Terminal::_basket._storage){
//        (Terminal::_warehouse[i.first]).update_quantity((i.second)*(-1));
//    }
//    Terminal::_basket.clear();
//    cout << endl << "Compra finalizada!" << endl;
}
void Terminal::c_clear_basket(){
    Terminal::_basket.clear();
}