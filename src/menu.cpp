#include "menu.h"

void sign_up() {

  int admin_or_client;
  bool repeat_registration = true; //repetir o cadastro caso haja algum erro

  while(repeat_registration) {

    cout << "--------------------" << endl
    << "Qual tipo de conta voce gostaria de criar?" << endl
    << "1 - Administrador" << endl << "2 - Cliente" << endl
    << "Digite 3 para voltar ao menu principal" << endl;
    cin >> admin_or_client;
    cout << endl;

    if(admin_or_client == 2) {
      register_user(2);
      repeat_registration = false;
    }
    else if(admin_or_client == 1){
      int key;

      cout << "Somente pessoas autorizadas podem criar esse tipo de conta!"
      << endl << "Digite a chave de acesso: ";
      cin >> key;
      cout << endl;

      if(key == ACCESS_KEY) {
        register_user(1);
        repeat_registration = false;
      }
      else
        cout << "Chave incorreta, tente novamente." << endl << endl;
    }
    else if(admin_or_client == 3)
      repeat_registration = false;

    else
      cout << "Comando invalido" << endl << endl;

  }
}


void register_user(int amdin_or_client) {

  fstream admins, clients;
  string name, name_in_file;
  string login, login_in_file;
  string password, password_in_file;
  string confirm_password;
  int a_or_c = amdin_or_client;

  bool valid_registration = false;

  while(!valid_registration) {

    bool valid_password = false;
    bool valid_login = true;

    cout << "--------------------" << endl;
    cout << "Nome: ";
    cin >> name;
    cout << "Login: ";
    cin >> login;
    cout << "Senha: ";
    cin >> password;
    cout << "Confirme sua senha: ";
    cin >> confirm_password;
    cout << endl;

    admins.open("admin-login.txt", ios::app | ios::in);
    while(!admins.eof()) { //percorre o registro de admin pra ver se o login ja existe

      admins >> name_in_file >> login_in_file >> password_in_file;

      if(login_in_file == login) {
        valid_login = false;
        break;
      }
    }
    admins.close();

    if(!valid_login){
      cout << "Esse login ja esta em uso, tente novamente" << endl << endl;
      break;
    }

    else{

      clients.open("client-login.txt", ios::app | ios::in);
      while(!clients.eof()) {

        clients >> name_in_file >> login_in_file >> password_in_file;

        if(login_in_file == login) {
          valid_login = false;
          break;
        }
      }
      clients.close();

      if(!valid_login) {
        cout << "Esse login ja esta em uso, tente novamente" << endl << endl;
        break;
      }
      else //se nao existir nos dois registros, torna o login valido
        valid_login = true;
    }

    if(confirm_password != password) //verifica se as senhas digitadas sao iguais
      cout << "As senhas digitadas nao correspondem" << endl << endl;

    else
      valid_password = true;


    if(valid_login && valid_password)
      valid_registration = true;

    if(valid_registration) { //cadastro eh valido quando login e senha passam pelos testes
      if(a_or_c == 1) { //se for admin, registra no arquivo dos admins

        admins.open("admin-login.txt", ios::app | ios::out);
        admins << name << " " << login << " " << password << endl;
        admins.close();

        cout << name << ", seu cadastro esta completo!" << endl << endl;

      }
      else if(a_or_c == 2) { //se for cliente, registra no arquivo dos clientes

        clients.open("client-login.txt", ios::app | ios::out);
        clients << name << " " << login << " " << password << endl;
        clients.close();

        cout << name << ", seu cadastro esta completo!" << endl << endl;
      }
    }
  }
}


void login() {

  ifstream admins, clients;
  string user_login, user_password;
  string name_in_file, login_in_file, password_in_file;
  bool user_exists = false;
  bool user_found = false;

  cout << "--------------------" << endl;
  cout << "Digite seu login: ";
  cin >> user_login;
  cout << "Senha: ";
  cin >> user_password;
  cout << endl;

  admins.open("admin-login.txt");
  while(!admins.eof()) {

    admins >> name_in_file >> login_in_file >> password_in_file;

    if(login_in_file == user_login) {
      if(password_in_file == user_password) { //se encontra o login e senha, mostra o painel

        Admin user_admin(name_in_file, login_in_file, password_in_file);
        admin_panel(&user_admin);
        user_found = true;
        user_exists = true;
        break;

      }
    }
  }
  admins.close();

  if(!user_found) { //se nao eh um admin, vai verificar se eh um cliente

    clients.open("client-login.txt");
    while(!clients.eof()) {

      clients >> name_in_file >> login_in_file >> password_in_file;

      if(login_in_file == user_login) {
        if(password_in_file == user_password) {

          Client user_client(name_in_file, login_in_file, password_in_file);
          client_panel(&user_client);
          user_exists = true;
          break;

        }
      }
    }
    clients.close();

  }

  if(!user_exists)
    cout << "Login e/ou senha incorretos" << endl << endl;

}


void admin_panel(Admin *user_admin) {

  bool close_panel = false;

  while(!close_panel) {
    int panel_option;

    cout << "--------------------" << endl;
    cout << "Bem-vindx, " << user_admin->get_name() << endl << endl
    << "O que voce gostaria de fazer?" << endl
    << "1 - Adicionar novo produto ao estoque" << endl
    << "2 - Alterar a quantidade de um produto" << endl
    << "3 - Alterar o preco de um produto" << endl
    << "4 - Remover um produto do estoque" << endl
    << "5 - Ver estoque" << endl << "6 - Logout" << endl;
    cin >> panel_option;
    cout << endl;

    switch(panel_option) {

      case 1:
        user_admin->add_product_storage();
        break;

      case 2:
        user_admin->change_product_quantity();
        break;

      case 3:
        user_admin->change_product_price();
        break;

      case 4:
        user_admin->remove_product();
        break;

      case 5:
        user_admin->show_storage();
        break;

      case 6:
        close_panel = true;
        break;

      default:
        cout << "Comando invalido" << endl << endl;
        break;

    }
  }
}


void client_panel(Client *user_client) {

  bool close_panel = false;

  while(!close_panel) {
    int panel_option;

    cout << "--------------------" << endl;
    cout << "Bem-vindx, " << user_client->get_name() << endl << endl;
    cout << "O que gostaria de fazer?" << endl
    << "1 - Pesquisar um produto" << endl
    << "2 - Ver carrinho" << endl
    << "3 - Logout" << endl;
    cin >> panel_option;
    cout << endl;

    switch(panel_option) {

      case 1:
        user_client->search_product();
        break;

      case 2:
        user_client->see_cart();
        break;

      case 3:
        close_panel = true;
        break;

      default:
        cout << "Comando invalido" << endl << endl;
        break;

    }
  }
}
