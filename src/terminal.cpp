#include "terminal.h"
#include <iostream>
#include <string.h>
#include <utility>
#include <stdio.h>

Terminal::Terminal(){
    shared_ptr<Basket> _basket;
    shared_ptr<Warehouse> _warehouse;
}
void Terminal::menu_home(){
    while(true){
        string cmd;
        cout << endl << "Digite um comando (help para a lista de opcoes): " << endl;
        while (getline (cin, cmd));
        cout << endl;
        
        if (strcmp(cmd.c_str(), "list products") == 0){
            _warehouse->list_products();
        }
        else if (strcmp(cmd.c_str(), "list basket") == 0){
            _basket->list_products();
            cout << endl << "Confrimar compra? (y/n)" << endl;
            char confirm;
            cin >> confirm;
            if (confirm == 'y'){
                // adicionar finalização da compra
            }
        }
        else if (strcmp(cmd.c_str(), "add product basket") == 0){
            this->menu_product_to_basket();
        }
        else if (strcmp(cmd.c_str(), "add product warehouse") == 0){
            this->menu_product_to_warehouse();
        }
        else if (strcmp(cmd.c_str(), "confirm purchase") == 0){
            this->menu_product_to_warehouse();
        }
        else if (strcmp(cmd.c_str(), "exit") == 0){
            break;
        }
        else {
            cout << endl << "Comando inválido!" << endl;
            this->print_help();
        }
    }
}

void Terminal::print_greetings(){
    cout << "Welcome " << this->_user->get_login() << "!" << endl;
}
void Terminal::print_help(){
    cout << "Ajuda e lista de comandos:" << endl;
}
void Terminal::menu_product_to_warehouse(){
    int category;

    while(true){
        cout << endl << "Adicionando Produto..." << endl;
        
        cout << "Selecione a categoria do produto que voce deseja adicionar oou qualquer outro valor para retornar:" << endl
             << "1 - Roupa" << endl
             << "2 - Sapato" << endl
             << "3 - Oculos de sol" << endl;
        cin >> category;
        cout << endl;
        
        switch (category){
            case 1:
                // Add roupa
            case 2:
                // Add sapato
            case 3:
                // add oculos
            default:
                return;
        }
    }

}
void Terminal::menu_product_to_basket(){

}