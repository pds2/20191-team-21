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


int Admin::choose_category() {

	int category;

  cout << "Selecione a categoria do produto que voce deseja adicionar"
	<< endl << "1 - Roupa" << endl << "2 - Sapato" << endl <<
	"3 - Oculos de sol" << endl << "Digite 4 para voltar" << endl;
  cin >> category;
	cout << endl;

	return category;

}


void Admin::case_clothes_add(string *type, string *brand, string *color,
														string *size_c, int *quantity, double *price) {

	string _type, _brand, _color, _size_c;
	int _quantity;
	double _price;

	cout << "Tipo do produto: ";
  cin >> _type;
	*type = std::move(_type);
  cout << "Marca: ";
  cin >> _brand;
	*brand = std::move(_brand);
  cout << "Cor: ";
  cin >> _color;
	*color = std::move(_color);
  cout << "Tamanho: ";
  cin >> _size_c;
	*size_c = std::move(_size_c);
	cout << "Quantidade: ";
	cin >> _quantity;
	*quantity = _quantity;
  cout << "Preco: ";
  cin >> _price;
	*price = _price;
	cout << endl;

}


bool Admin::search_clothes(string type, string brand, string color,
													string size_c, int quantity, double price) {

	fstream clothes_strg;
	string search_type, search_brand, search_color, search_size_c;
	int search_quantity;
	double search_price;
	bool product_exists = false;

  clothes_strg.open("storage-clothes.txt", ios::in);
  while(!clothes_strg.eof()) {
		clothes_strg >> search_type >> search_brand >> search_color
		>> search_size_c >> search_quantity >> search_price;

		//le todas as linhas do arquivo e procura o produto escolhido
		if(search_type == type) {
			if(search_brand == brand) {
				if(search_color == color) {
					if(search_size_c == size_c) {
						product_exists = true;
					}
				}
			}
		}
	}
	clothes_strg.close();

	return product_exists;
}


void Admin::add_clothes(string type, string brand, string color,
												string size_c, int quantity, double price) {

	fstream clothes_strg;
	Clothes new_clothes(type, brand, color, size_c, quantity, price);

	//abre o arquivo no mode de gravacao no fim do arquivo
	clothes_strg.open("storage-clothes.txt", ios::out | ios::app);
	clothes_strg << endl << new_clothes.get_type() << " " << new_clothes.get_brand()
	<< " " << new_clothes.get_color() << " " << new_clothes.get_size() << " " <<
	new_clothes.get_quantity() << " " << new_clothes.get_price();

	cout << "Produto adicionado ao estoque com sucesso." << endl << endl;

	clothes_strg.close();

}


void Admin::case_shoes_add(string *type, string *brand, string *color, int *size_s, int *quantity, double *price) {

	string _type, _brand, _color;
	int _quantity, _size_s;
	double _price;

	cout << "Tipo do produto: ";
  cin >> _type;
	*type = std::move(_type);
  cout << "Marca: ";
  cin >> _brand;
	*brand = std::move(_brand);
  cout << "Cor: ";
  cin >> _color;
	*color = std::move(_color);
  cout << "Tamanho: ";
  cin >> _size_s;
	*size_s = _size_s;
	cout << "Quantidade: ";
	cin >> _quantity;
	*quantity = _quantity;
  cout << "Preco: ";
  cin >> _price;
	*price = _price;
	cout << endl;

}


bool Admin::search_shoes(string type, string brand, string color,
												int size_s, int quantity, double price) {

	fstream shoes_strg;
	string search_type, search_brand, search_color;
	int search_quantity, search_size_s;
	double search_price;
	bool product_exists = false;


  shoes_strg.open("storage-shoes.txt", ios::in);
  while(!shoes_strg.eof()) {
	shoes_strg >> search_type >> search_brand >> search_color
	>> search_size_s >> search_quantity >> search_price;

		if(search_type == type) {
			if(search_brand == brand) {
				if(search_color == color) {
					if(search_size_s == size_s) {
						product_exists = true;
					}
				}
			}
		}
	}
	shoes_strg.close();

	return product_exists;

}

//void Admin::add_shoes();

void Admin::case_sunglasses_add(string *brand, string* color, int* quantity, double* price){
	cout << "Marca do produto: ";
	string _brand, _color;
	int _quantity;
	double _price;
  
	cin >> _brand;
	*brand = std::move(_brand);
  cout << "Cor: ";
  cin >> _color;
	*color = std::move(_color);
	cout << "Quantidade: ";
  cin >> _quantity;
	*quantity = _quantity;
  cout << "Preco: ";
  cin >> _price;
	*price = _price;
	cout << endl;

}

//bool Admin::search_sunglasses()

//void Admin::add_sunglasses()

void Admin::add_product_storage() {

  fstream clothes_strg, shoes_strg, sunglasses_strg;
  string brand, type, color, size_c;
	string search_brand, search_type, search_color;
	int size_s, search_quantity;
  int quantity;
	double price, search_price;

  bool add_product = true;
	bool product_exists = false;


  while(add_product) {

	  switch(Admin::choose_category()) {

  	  case 1:
				Admin::case_clothes_add(&type, &brand, &color, &size_c, &quantity, &price);

				if(Admin::search_clothes(type, brand, color, size_c, quantity, price))
					cout << "Esse produto ja existe no estoque." << endl << endl;
				else{
					Admin::add_clothes(type, brand, color, size_c, quantity, price);
				}
				break;

			case 2:
        Admin::case_shoes_add(&type, &brand, &color, &size_s, &quantity, &price);

				if(Admin::search_shoes(type, brand, color, size_s, quantity, price))
					cout << "Esse produto ja existe no estoque." << endl << endl;
				else{

					Shoes new_shoes(type, brand, color, size_s, quantity, price);

					//abre o arquivo no mode de gravacao no fim do arquivo
					shoes_strg.open("storage-shoes.txt", ios::out | ios::app);
					shoes_strg << endl << new_shoes.get_type() << " " << new_shoes.get_brand()
					<< " " << new_shoes.get_color() << " " << new_shoes.get_size() << " " <<
					new_shoes.get_quantity() << " " << new_shoes.get_price();

					cout << "Produto adicionado ao estoque com sucesso." << endl << endl;

				}
				shoes_strg.close();
				break;

			case 3:
       	Admin::case_sunglasses_add(&brand, &color, &quantity, &price);

    	  sunglasses_strg.open("storage-sunglasses.txt", ios::in);
        while(!sunglasses_strg.eof()) {
				sunglasses_strg >> search_brand >> search_color
				>> search_quantity >> search_price;

					if(search_brand == brand && search_color == color) {
						product_exists = true;
					}
				}
				sunglasses_strg.close();

				if(product_exists)
					cout << "Esse produto ja existe no estoque." << endl << endl;
				else{

					Sunglasses new_sunglasses(brand, color, quantity, price);

					//abre o arquivo no mode de gravacao no fim do arquivo
					sunglasses_strg.open("storage-sunglasses.txt", ios::out | ios::app);
					sunglasses_strg << endl << new_sunglasses.get_brand() << " " <<
					new_sunglasses.get_color() << " " << new_sunglasses.get_quantity()
					<< " " << new_sunglasses.get_price();

					cout << "Produto adicionado ao estoque com sucesso." << endl << endl;

				}
				sunglasses_strg.close();
				break;

			case 4:
				add_product = false;
				break;

			default:
				cout << "Comando invalido" << endl << endl;
				break;

    }
	}
}


void Admin::case_clothes_qt(string *type, string *brand, string *color, string *size_c, int *new_quantity){
	string _type, _brand, _color, _size_c;
	int _new_quantity;
				cout << "Tipo do produto: ";
				cin >> _type;
				*type = std::move(_type);
				cout << "Marca: ";
				cin >> _brand;
				*brand = std::move(_brand);
				cout << "Cor: ";
				cin >> _color;
				*color = std::move(_color);
				cout << "Tamanho: ";
				cin >> _size_c;
				*size_c = _size_c;
				cout << "Insira a nova quantidade: ";
				cin >> _new_quantity;
				*new_quantity = _new_quantity;

				/*//excecao
				if(new_price <= 0) {
	  			cout << endl << "Preco invalido." << endl << endl
	  			;
	  			break;
		}*/
	}

void Admin::change_product_quantity() {

  fstream clothes_strg, shoes_strg, sunglasses_strg;
  string type, brand, color, size_c;
	string search_type, search_brand, search_color, search_size_c;
	int search_quantity, new_quantity, search_size_s, size_s;
  double search_price;

  bool product_exists = false;
  bool change_menu = true;

  vector<string> types;
  vector<string> brands;
  vector<string> colors;
  vector<string> sizes_c;
  vector<int> sizes_s;
  vector<int> quantities;
  vector<double> prices;

  while(change_menu) {

    switch(Admin::choose_category()) {

			case 1:
			{
				Admin::case_clothes_qt(&type, &brand, &color, &size_c, &new_quantity);


//search_clothes_qt
				int aux = 0;

				//abre com ios::in pois sera apenas leitura
				clothes_strg.open("storage-clothes.txt", ios::in);
				while(!clothes_strg.eof()) {
	  			clothes_strg >> search_type >> search_brand >> search_color >>
					search_size_c >> search_quantity >> search_price;


          if(type == search_type) {
            if(brand == search_brand) {
              if(color == search_color) {
                if(size_c == search_size_c) {
								  product_exists = true;
									aux = 0;
                }
								else aux++;
              }
							else aux++;
	    			}
						else aux++;
	  			}
					else aux++;

	  			if(aux == 0) {
						types.push_back(search_type);
		  			brands.push_back(search_brand);
		  			colors.push_back(search_color);
		  			sizes_c.push_back(search_size_c);
		  			quantities.push_back(new_quantity);
		  			prices.push_back(search_price);
					}
					else {
	    			types.push_back(search_type);
	    			brands.push_back(search_brand);
	    			colors.push_back(search_color);
	    			sizes_c.push_back(search_size_c);
	    			quantities.push_back(search_quantity);
	    			prices.push_back(search_price);
						aux = 0;
	  			}
				}
				clothes_strg.close();


//change_clothes_qt
				int s = types.size();

				if(!product_exists)
	  			cout << endl << "Esse produto nao existe no estoque." << endl << endl;
				else {
	  			/*aberto com ios::trunc para que as informacoes do arquivo sejam deletadas
	  			e as novas, gravadas em um documento em branco*/
	  			clothes_strg.open("storage-clothes.txt", ios::out | ios::trunc);
	  			for(int i = 0; i < s; i++) {
	    			if(i == 0) {
	      			clothes_strg << types[i] << " " << brands[i] << " " << colors[i] << " "
	      			<< sizes_c[i] << " " << quantities[i] << " " << prices[i];
						}
	    			else {
	      			clothes_strg << endl << types[i] << " " << brands[i] << " " << colors[i]
	      			<< " " << sizes_c[i] << " " << quantities[i] << " " << prices[i];
						}
	  			}
	  			clothes_strg.close();

					cout << endl << "Quantidade alterada com sucesso." << endl << endl;
				}

				for(int i = s; i > 0; i--) {
	  			types.pop_back();
	  			brands.pop_back();
	  			colors.pop_back();
	  			sizes_c.pop_back();
	  			quantities.pop_back();
	  			prices.pop_back();
				}

				change_menu = false;
				break;
			}

      case 2:
			{
//void case_shoes_qt();
				cout << "Tipo do produto: ";
				cin >> type;
				cout << "Marca: ";
				cin >> brand;
				cout << "Cor: ";
				cin >> color;
				cout << "Tamanho: ";
				cin >> size_s;
				cout << "Insira a nova quantidade: ";
				cin >> new_quantity;

//excecao
				if(new_quantity < 0) {
	  			cout << endl << "Quantidade invalida." << endl << endl;
	  			break;
				}


//search_shoes_qt
				int aux = 0;

				//abre com ios::in pois sera apenas leitura
				shoes_strg.open("storage-shoes.txt", ios::in);
				while(!shoes_strg.eof()) {
	  			shoes_strg >> search_type >> search_brand >> search_color >>
					search_size_s >> search_quantity >> search_price;

	  			//se for o produto procurado, adiciona new_quantity no lugar da antiga quantidade
          if(type == search_type) {
            if(brand == search_brand) {
              if(color == search_color) {
                if(size_s == search_size_s) {
									product_exists =true;
									aux = 0;
                }
								else aux++;
              }
							else aux++;
	    			}
						else aux++;
	  			}
					else aux++;

	  			if(aux == 0) {
	    			types.push_back(search_type);
	    			brands.push_back(search_brand);
	    			colors.push_back(search_color);
	    			sizes_s.push_back(search_size_s);
	  	  		quantities.push_back(new_quantity);
		    		prices.push_back(search_price);
		  			}
					else {
		  			types.push_back(search_type);
		  			brands.push_back(search_brand);
			  		colors.push_back(search_color);
			  		sizes_s.push_back(search_size_s);
			  		quantities.push_back(search_quantity);
		  			prices.push_back(search_price);
						aux = 0;
					}
				}
			shoes_strg.close();


//change_shoes_qt
			int s = types.size();

				if(!product_exists)
	  			cout << endl << "Esse produto nao existe no estoque." << endl << endl;
				else {
	  			/*aberto com ios::trunc para que as informacoes do arquivo sejam deletadas
	  			e as novas, gravadas em um documento em branco*/
	  			shoes_strg.open("storage-shoes.txt", ios::out | ios::trunc);
	  			for(int i = 0; i < s; i++) {
	    			if(i == 0)
	      			shoes_strg << types[i] << " " << brands[i] << " " << colors[i] << " "
	      			<< sizes_s[i] << " " << quantities[i] << " " << prices[i];
	    			else
	      			shoes_strg << endl << types[i] << " " << brands[i] << " " << colors[i]
	      			<< " " << sizes_s[i] << " " << quantities[i] << " " << prices[i];
	  			}
	  			shoes_strg.close();

					cout << endl << "Quantidade alterada com sucesso." << endl << endl;
				}

				for(int i = s; i > 0; i--) {
	  			types.pop_back();
	  			brands.pop_back();
	  			colors.pop_back();
	  			sizes_s.pop_back();
	  			quantities.pop_back();
	  			prices.pop_back();
				}

				change_menu = false;
				break;
			}

      case 3:
			{
//void case_sunglasses_qt()
				cout << "Marca do produto: ";
				cin >> brand;
				cout << "Cor: ";
				cin >> color;
				cout << "Insira a nova quantidade: ";
				cin >> new_quantity;
//excecao
				if(new_quantity < 0) {
	  			cout << endl << "Quantidade invalida." << endl << endl;
	  			break;
				}


//search - arqv
				int aux = 0;

				//abre com ios::in pois sera apenas leitura
				sunglasses_strg.open("storage-sunglasses.txt", ios::in);
				while(!sunglasses_strg.eof()) {
	  			sunglasses_strg >> search_brand >> search_color >> search_quantity >>
					search_price;

          if(brand == search_brand) {
            if(color == search_color) {
							product_exists = true;
							aux = 0;
	    			}
						else aux++;
	  			}
					else aux++;

					if(aux == 0) {
	    			brands.push_back(search_brand);
	    			colors.push_back(search_color);
	    			quantities.push_back(new_quantity);
	    			prices.push_back(search_price);
					}
	  			else {
    			  brands.push_back(search_brand);
      			colors.push_back(search_color);
      			quantities.push_back(search_quantity);
      			prices.push_back(search_price);
						aux = 0;
	  			}
				}
				sunglasses_strg.close();


//change - arqv
				int s = brands.size();

				if(!product_exists)
	  			cout << endl << "Esse produto nao existe no estoque." << endl << endl;
				else {
	  			/*aberto com ios::trunc para que as informacoes do arquivo sejam deletadas
	  			e as novas, gravadas em um documento em branco*/
	  			sunglasses_strg.open("storage-sunglasses.txt", ios::out | ios::trunc);
	  			for(int i = 0; i < s; i++) {
	    			if(i == 0) {
	      			sunglasses_strg << brands[i] << " " << colors[i] << " " << quantities[i]
              << " " << prices[i];
						}
	    			else {
	      			sunglasses_strg << endl << brands[i] << " " << colors[i] << " " <<
	      			quantities[i] << " " << prices[i];
						}
	  			}
	  			sunglasses_strg.close();

					cout << endl << "Quantidade alterada com sucesso." << endl << endl;
				}

				for(int i = s; i > 0; i--) {;
	  			brands.pop_back();
	  			colors.pop_back();
	  			quantities.pop_back();
	  			prices.pop_back();
				}

				change_menu = false;
				break;
			}

      case 4:
				change_menu = false;
				break;

      default:
				cout << endl << "Comando invalido." << endl << endl;
				break;
    }
  }
}


void Admin::case_clothes_prc(string *type, string *brand, string *color, string *size_c, double *new_price){
	string _type, _brand, _color, _size_c;
	double _new_price;

	cout << "Tipo do produto: ";
	cin >> _type;
	*type = std::move(_type);
	cout << "Marca: ";
	cin >> _brand;
	*brand = std::move(_brand);
	cout << "Cor: ";
	cin >> _color;
	*color = std::move(_color);
	cout << "Tamanho: ";
	cin >> _size_c;
	*size_c = _size_c;
	cout << "Insira o novo preco: ";
	cin >> _new_price;
	*new_price = _new_price;

	/*//excecao
	if(new_price <= 0) {
		cout << endl << "Preco invalido." << endl << endl;
	  break;
	}*/
}


void Admin::case_shoes_prc(string *type, string *brand, string *color, int *size_s, double *new_price){
	string _type, _brand, _color, _size_c;
	int _size_s;
	double _new_price;

	cout << "Tipo do produto: ";
	cin >> _type;
	*type = std::move(_type);
	cout << "Marca: ";
	cin >> _brand;
	*brand = std::move(_brand);
	cout << "Cor: ";
	cin >> _color;
	*color = std::move(_color);
	cout << "Tamanho: ";
	cin >> _size_s;
	*size_s = _size_s;
	cout << "Insira o novo preco: ";
	cin >> _new_price;
	*new_price = _new_price;

/*/excecao
	if(new_price <= 0) {
		cout << endl << "Preco invalido." << endl << endl;
		break;
	}*/
}


void Admin::case_sunglasses_prc(string* brand, string* color, double* new_price){
	string _brand, _color;
	double _new_price;

	cout << "Marca do produto: ";
	cin >> _brand;
	*brand = move(_brand);
	cout << "Cor: ";
	cin >> _color;
	*color = move(_color);
	cout << "Insira o novo preco: ";
	cin >> _new_price;
	*new_price = _new_price;

//excecao
/* if(new_price <= 0) {
		cout << endl << "Preco invalido." << endl << endl;
		break;
	}*/
}


void Admin::change_product_price() {

  fstream clothes_strg, shoes_strg, sunglasses_strg;
  string type, brand, color, size_c;
	string search_type, search_brand, search_color, search_size_c;
	int search_quantity, size_s, search_size_s;
  double search_price, new_price;

  bool product_exists = false;
  bool change_menu = true;

  vector<string> types;
  vector<string> brands;
  vector<string> colors;
  vector<string> sizes_c;
  vector<int> sizes_s;
  vector<int> quantities;
  vector<double> prices;

  while(change_menu) {


    switch(Admin::choose_category()) {

      case 1:
			{

				Admin::case_clothes_prc(&type, &brand, &color, &size_c, &new_price);


//search - arqv
				int aux = 0;

				//abre com ios::in pois sera apenas leitura
				clothes_strg.open("storage-clothes.txt", ios::in);
				while(!clothes_strg.eof()) {
	  			clothes_strg >> search_type >> search_brand >> search_color >>
					search_size_c >> search_quantity >> search_price;

          if(type == search_type) {
            if(brand == search_brand) {
              if(color == search_color) {
                if(size_c == search_size_c) {
									product_exists = true;
									aux = 0;
                }
								else aux++;
              }
							else aux++;
	    			}
						else aux++;
	  			}
					else aux++;

					if(aux == 0) {
						types.push_back(search_type);
		  			brands.push_back(search_brand);
						colors.push_back(search_color);
	  				sizes_c.push_back(search_size_c);
						quantities.push_back(search_quantity);
	  				prices.push_back(new_price);
					}
	  			else {
	    			types.push_back(search_type);
	    			brands.push_back(search_brand);
	    			colors.push_back(search_color);
	    			sizes_c.push_back(search_size_c);
	    			quantities.push_back(search_quantity);
				    prices.push_back(search_price);
	    			aux = 0;
	  			}
				}
				clothes_strg.close();


//change - arqv
				int s = types.size();

				if(!product_exists)
	  			cout << "Esse produto nao existe no estoque." << endl << endl;
				else {
	  			/*aberto com ios::trunc para que as informacoes do arquivo sejam deletadas
	  			e as novas, gravadas em um documento em branco*/
	  			clothes_strg.open("storage-clothes.txt", ios::out | ios::trunc);
	  			for(int i = 0; i < s; i++) {
	    			if(i == 0) {
	      			clothes_strg << types[i] << " " << brands[i] << " " << colors[i] << " "
	      			<< sizes_c[i] << " " << quantities[i] << " " << prices[i];
						}
	    			else {
	      			clothes_strg << endl << types[i] << " " << brands[i] << " " << colors[i]
	      			<< " " << sizes_c[i] << " " << quantities[i] << " " << prices[i];
						}
	  			}
	  			clothes_strg.close();

					cout << endl << "Preco alterado com sucesso." << endl << endl;
				}

				for(int i = s; i > 0; i--) {
	  			types.pop_back();
	  			brands.pop_back();
	  			colors.pop_back();
	  			sizes_c.pop_back();
	  			quantities.pop_back();
	  			prices.pop_back();
				}

				change_menu = false;
				break;
			}

      case 2:
			{
				Admin::case_shoes_prc(&type, &brand, &color, &size_s, &new_price);


//search - arqv
				int aux = 0;

				//abre com ios::in pois sera apenas leitura
				shoes_strg.open("storage-shoes.txt", ios::in);
				while(!shoes_strg.eof()) {
	  			shoes_strg >> search_type >> search_brand >> search_color >>
					search_size_s >> search_quantity >> search_price;

          if(type == search_type) {
            if(brand == search_brand) {
              if(color == search_color) {
                if(size_s == search_size_s) {
									product_exists = false;
									aux = 0;
                }
								else aux++;
              }
							else aux++;
	    			}
						else aux++;
	  			}
					else aux++;

					if(aux == 0) {
						types.push_back(search_type);
		  			brands.push_back(search_brand);
		  			colors.push_back(search_color);
						sizes_s.push_back(search_size_s);
		  			quantities.push_back(search_quantity);
		  			prices.push_back(new_price);
					}
	  			else {
	    			types.push_back(search_type);
	    			brands.push_back(search_brand);
	    			colors.push_back(search_color);
	    			sizes_s.push_back(search_size_s);
	    			quantities.push_back(search_quantity);
	    			prices.push_back(search_price);
	    			aux = 0;
	  			}
				}
				shoes_strg.close();


//change - arqv
				int s = types.size();

				if(!product_exists)
	  			cout << endl << "Esse produto nao existe no estoque." << endl << endl;
				else {
	  			/*aberto com ios::trunc para que as informacoes do arquivo sejam deletadas
	  			e as novas, gravadas em um documento em branco*/
	  			shoes_strg.open("storage-shoes.txt", ios::out | ios::trunc);
	  			for(int i = 0; i < s; i++) {
	    			if(i == 0) {
	      			shoes_strg << types[i] << " " << brands[i] << " " << colors[i] << " "
	      			<< sizes_s[i] << " " << quantities[i] << " " << prices[i];
						}
	    			else {
	      			shoes_strg << endl << types[i] << " " << brands[i] << " " << colors[i]
	      			<< " " << sizes_s[i] << " " << quantities[i] << " " << prices[i];
						}
	  			}
	  			shoes_strg.close();

					cout << endl << "Preco alterado com sucesso." << endl << endl;
				}

				for(int i = s; i > 0; i--) {
	  			types.pop_back();
	  			brands.pop_back();
	  			colors.pop_back();
	  			sizes_s.pop_back();
				  quantities.pop_back();
	  			prices.pop_back();
				}

				change_menu = false;
				break;
			}

      case 3:
			{
				Admin::case_sunglasses_prc(&brand, &color, &new_price);


//search - arqv
				int aux = 0;

				//abre com ios::in pois sera apenas leitura
				sunglasses_strg.open("storage-sunglasses.txt", ios::in);
				while(!shoes_strg.eof()) {
	  			sunglasses_strg >> search_brand >> search_color >> search_quantity
					>> search_price;

          if(brand == search_brand) {
            if(color == search_color) {
							product_exists = true;
							aux = 0;
	    			}
						else aux++;
	  			}
					else aux++;

					if(aux == 0) {
						brands.push_back(search_brand);
						colors.push_back(search_color);
						quantities.push_back(search_quantity);
						prices.push_back(new_price);
					}
	  			else {
	    			brands.push_back(search_brand);
	    			colors.push_back(search_color);
	    			quantities.push_back(search_quantity);
	    			prices.push_back(search_price);
	    			aux = 0;
	  			}
				}
				sunglasses_strg.close();


//change - arqv
				int s = brands.size();

				if(!product_exists)
	  			cout << endl << "Esse produto nao existe no estoque." << endl << endl;
				else {
				  /*aberto com ios::trunc para que as informacoes do arquivo sejam deletadas
	  			e as novas, gravadas em um documento em branco*/
	  			sunglasses_strg.open("storage-sunglasses.txt", ios::out | ios::trunc);
	  			for(int i = 0; i < s; i++) {
	    			if(i == 0) {
	      			sunglasses_strg << brands[i] << " " << colors[i] << " " << quantities[i]
	      			<< " " << prices[i];
						}
	    			else {
		      		sunglasses_strg << endl << brands[i] << " " << colors[i] << " " <<
		      		quantities[i] << " " << prices[i];
						}
	  			}
	  			sunglasses_strg.close();

					cout << endl << "Preco alterado com sucesso." << endl << endl;
				}

				for(int i = brands.size(); i > 0; i--) {
	  			brands.pop_back();
	  			colors.pop_back();
	  			quantities.pop_back();
		  		prices.pop_back();
				}

				change_menu = false;
				break;
			}

      case 4:
				change_menu = false;
				break;

      default:
				cout << endl << "Comando invalido." << endl << endl;
				break;
    }
  }
}


void Admin::remove_product() {

  fstream clothes_strg, shoes_strg, sunglasses_strg;
  string type, brand, color, size_c;
  string search_type, search_brand, search_color, search_size_c;
  int size_s, search_quantity, search_size_s;
  double search_price;

  bool product_exists = false;
  bool remove_menu = true;

  vector<string> types;
  vector<string> brands;
  vector<string> colors;
  vector<string> sizes_c;
  vector<int> sizes_s;
  vector<int> quantities;
  vector<double> prices;


  while(remove_menu) {

    switch(Admin::choose_category()) {

      case 1:
			{
				//case
        cout << "Tipo do produto: ";
        cin >> type;
        cout << "Marca: ";
        cin >> brand;
        cout << "Cor: ";
        cin >> color;
        cout << "Tamanho: ";
        cin >> size_c;
        cout << endl;

//
				int aux = 0;

        clothes_strg.open("storage-clothes.txt", ios::in);
        while(!clothes_strg.eof()) {
	  			clothes_strg >> search_type >> search_brand >> search_color >>
					search_size_c >> search_quantity >> search_price;

          if(type == search_type) {
	    			if(brand == search_brand) {
	      			if(color == search_color) {
	        			if(size_c == search_size_c) {
									aux = 0;
									product_exists = true;
								}
								else aux++;
	      			}
							else aux++;
	    			}
						else aux++;
	  			}
	  			else aux++;

					if(aux != 0) {
						types.push_back(search_type);
		  			brands.push_back(search_brand);
		  			colors.push_back(search_color);
		  			sizes_c.push_back(search_size_c);
		  			quantities.push_back(search_quantity);
		  			prices.push_back(search_price);
						aux = 0;
					}
        }
				clothes_strg.close();

//
				int s = types.size();

        if(!product_exists)
	  			cout << endl << "Esse produto nao existe no estoque." << endl << endl;
        else {
	  			/*aberto com ios::trunc para que as informacoes do arquivo sejam deletadas
	  			e as novas, gravadas em um arquivo em branco*/
	  			clothes_strg.open("storage-clothes.txt", ios::out | ios::trunc);
	  			for(int i = 0; i < s; i++) {
	    			if(i == 0) {
	      			clothes_strg << types[i] << " " << brands[i] << " " << colors[i] << " " <<
	      			sizes_c[i] << " " << quantities[i] << " " << prices[i];
						}
	    			else {
	      			clothes_strg << endl << types[i] << " " << brands[i] << " "  << colors[i] << " "
	      			<< sizes_c[i] << " " << quantities[i] << " "  << prices[i];
						}
					}
	  			clothes_strg.close();
					cout << endl << "Produto removido do estoque com sucesso." << endl << endl;
        }

        for(int i = s; i > 0; i--) {
	  			types.pop_back();
	  			brands.pop_back();
	  			colors.pop_back();
	  			sizes_c.pop_back();
	  			quantities.pop_back();
	 				prices.pop_back();
        }
				remove_menu = false;
        break;
			}

      case 2:
			{
				//case
        cout << "Tipo do produto: ";
        cin >> type;
        cout << "Marca: ";
        cin >> brand;
        cout << "Cor: ";
        cin >> color;
        cout << "Tamanho: ";
        cin >> size_s;
        cout << endl;

        shoes_strg.open("storage-shoes.txt", ios::in);
        while(!shoes_strg.eof()) {
	  			shoes_strg >> search_type >> search_brand >> search_color >> search_size_s
					>> search_quantity >> search_price;

//
					int aux = 0;

	  			if(type == search_type) {
	    			if(brand == search_brand) {
	      			if(color == search_color) {
	        			if(size_s == search_size_s) {
									aux = 0;
									product_exists = true;
	      			  }
								else aux++;
	      			}
							else aux++;
	    			}
						else aux++;
	  			}
					else aux++;

					if(aux != 0) {
						types.push_back(search_type);
		  			brands.push_back(search_brand);
		  			colors.push_back(search_color);
		  			sizes_s.push_back(search_size_s);
		  			quantities.push_back(search_quantity);
		  			prices.push_back(search_price);
						aux = 0;
					}
        }
				shoes_strg.close();

//
				int s = types.size();

        if(!product_exists)
	  			cout << endl << "Esse produto nao existe no estoque." << endl << endl;
        else {
	  			/*aberto com ios::trunc para que as informacoes do arquivo sejam deletadas
	  			e as novas, gravadas em um arquivo em branco*/
	  			shoes_strg.open("storage-shoes.txt", ios::out | ios::trunc);
	  			for(int i = 0; i < s; i++) {
	    			if(i == 0) {
	      			shoes_strg << types[i] << " " << brands[i] << " "  << colors[i] << " "  <<
							sizes_s[i] << " "  << quantities[i] << " "  << prices[i];
						}
	    			else {
	      			shoes_strg << endl << types[i] << " "  << brands[i] << " "  << colors[i] <<
							sizes_s[i] << " " << quantities[i] << " "  << prices[i];
						}
	  			}
	  			shoes_strg.close();
        	cout << endl << "Produto removido do estoque com sucesso." << endl << endl;
        }

        for(int i = s; i > 0; i--) {
	  			types.pop_back();
	  			brands.pop_back();
	  			colors.pop_back();
	  			sizes_s.pop_back();
	  			quantities.pop_back();
	  			prices.pop_back();
        }

				remove_menu = false;
        break;
			}

      case 3:
			{
				//case
        cout << "Marca do produto: ";
        cin >> brand;
        cout << "Cor: ";
        cin >> color;
        cout << endl;

//
				int aux = 0;

        sunglasses_strg.open("storage-sunglasses.txt", ios::in);
        while(!sunglasses_strg.eof()) {
    			sunglasses_strg >> search_brand >> search_color >> search_quantity >> search_price;

	    		if(brand == search_brand) {
	      		if(color == search_color) {
		  				product_exists = true;
							aux = 0;
	    			}
						else aux++;
	  			}
					else aux++;

    			if(aux != 0) {
						brands.push_back(search_brand);
		  			colors.push_back(search_color);
		  			quantities.push_back(search_quantity);
		  			prices.push_back(search_price);
						aux = 0;
					}
      	}
				sunglasses_strg.close();

//
				int s = brands.size();

        if(!product_exists)
	  			cout << endl << "Esse produto nao existe no estoque." << endl << endl;
      	else {
	  			/*aberto com ios::trunc para que as informacoes do arquivo sejam deletadas
	  			e as novas, gravadas em um arquivo em branco*/
	  			sunglasses_strg.open("storage-sunglasses.txt", ios::out | ios::trunc);
	  			for(int i = 0; i < s; i++) {
	    			if(i == 0)
	      			sunglasses_strg << brands[i] << colors[i] << quantities[i] << prices[i];
	    			else
	      			sunglasses_strg << endl << brands[i] << colors[i] << quantities[i] << prices[i];
	  			}
	  			sunglasses_strg.close();
        }

        for(int i = s; i > 0; i--) {
	  			brands.pop_back();
	  			colors.pop_back();
	  			quantities.pop_back();
	  			prices.pop_back();
        }

        cout << endl << "Produto removido do estoque com sucesso." << endl << endl;
				remove_menu = false;
        break;
			}

      case 4:
	  		remove_menu = false;
	  		break;


			default:
	  		cout << endl << "Comando invalido!" << endl << endl;
	  		break;

    }
  }
}

void Admin::show_storage() {

    ifstream clothes_strg, shoes_strg, sunglasses_strg;
    int quantity_c, quantity_s, quantity, size_s;
    string type_c, type_s, type, brand_c, brand_s, brand;
    string color_c, color_s, color, size_c;
    double price_c, price_s, price;

    clothes_strg.open("storage-clothes.txt");
    while(!clothes_strg.eof()) {
        clothes_strg >> type_c >> brand_c >> color_c >>
        size_c >> quantity_c >> price_c;
        cout << "Produto: " << type_c << " " << brand_c << endl <<
        "Tamanho: " << size_c << " | Cor: " << color_c << endl <<
        "Quantidade: " << quantity_c << endl << "Preco: " <<
        price_c << endl << endl;
    }
    clothes_strg.close();

    shoes_strg.open("storage-shoes.txt");
    while(!shoes_strg.eof()) {
        shoes_strg >> type_s >> brand_s >> color_s >>
        size_s >> quantity_s >> price_s;
        cout << "Produto: " << type_s << " " << brand_s << endl <<
        "Tamanho: " << size_s << " | Cor: " << color_s << endl <<
        "Quantidade: " << quantity_s << endl << "Preco: "
        << price_s << endl << endl;
    }
    shoes_strg.close();

    sunglasses_strg.open("storage-sunglasses.txt") ;
    while(!sunglasses_strg.eof()) {
        sunglasses_strg >> brand >> color >> quantity >> price;
        cout << "Produto: Oculos " << brand << endl <<
        "Cor: " << color << endl << "Quantidade: " <<
        quantity << endl << "Preco: " << price << endl << endl;
    }
    sunglasses_strg.close();

}
