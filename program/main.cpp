#include "menu.h"

int main() {

  bool store_is_open = true; //vai ficar aberta enquanto o user nao pedir pra fechar

  while(store_is_open) {

    int sign_in_or_up; //define se o user quer logar ou cadastrar

    cout << "Bem-vindx ao e-commerce!" << endl
    << "O que voce gostaria de fazer?" << endl << "1 - Se cadastrar" << endl
    << "2 - Fazer login" << endl << "3 - Sair da loja" << endl;
    cin >> sign_in_or_up;
    cout << endl;

    switch(sign_in_or_up) {

      case 1:
        sign_up();
        break;

      case 2:
        login();
        break;

      case 3:
        store_is_open = false;
        break;

      default:
        cout << "Opcao invalida." << endl << endl;
        break;

    }

  }

  return 0;
}
