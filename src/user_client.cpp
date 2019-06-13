// #include "user_client.h"
// 
// //CONSTRUCTOR
// Client::Client(string name, string login, string password) : User(std::move(name), std::move(login), std::move(password))
// {}
// 
// //GETTERS
// string Client::get_name(){
//     return this->_name;
// }
// string Client::get_login(){
//     return this->_login;
// }
// string Client::get_password(){
//     return this->_password;
// }
// 
// //MAP FUNCTIONS
// void Client::add_product (const shared_ptr<Product> product, unsigned int quantity){
// 
//     map<shared_ptr<Product>, unsigned int>::iterator it = cart.find(product);
// 
//     if (it != cart.end()){
//         it->second += quantity;
//         return;
//     }
//     else {
//         cart.insert(pair<shared_ptr<Product>, unsigned int>(product, quantity));
//     }
// }
// 
// //NEED ERROR HANDLING!!
// void Client::remove_product (const shared_ptr<Product> product, unsigned int quantity){
//     map<shared_ptr<Product>, unsigned int>::iterator it = cart.find(product);
// 
//     if (it != cart.end()){
//         it->second -= quantity;
//         if (it->second > 0){
//             return;
//         }
//     }
//     cart.erase(it);
// }
// void Client::list_products(){
//     map<shared_ptr<Product>, unsigned int>::iterator it;
// 
//     cout << "Seu Carrinho" << endl;
//     for (auto& i : cart) i.first->print();
// }
// 
// void Client::see_cart() {
// 
// 
// }
// 