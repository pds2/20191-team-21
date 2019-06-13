#ifndef ADMIN_H_PDS
#define ADMIN_H_PDS

#include "user.h"

class Admin : public User {

public:
    //CONSTRUCTOR
    Admin(string name, string login, string password);

    //GETTERS
    string get_name() override;
    string get_login() override;
    string get_password() override;

    //METHODS
    int choose_category();


    void case_clothes_add(string *type, string *brand, string *color, string *size_c, int *quantity, double *price);    
    bool search_clothes(string type, string brand, string color, string size_c, int quantity, double price);
    void add_clothes(string type, string brand, string color, string size_c, int quantity, double price);
    void case_shoes_add(string *type, string *brand, string *color,int *size_s, int *quantity, double *price);
    bool search_shoes(string type, string brand, string color, int size_s, int quantity, double price);
    //void add_shoes();
    void case_sunglasses_add(string *brand, string* color, int* quantity, double* price);
    //bool search_sunglasses();
    //void add_sunglasses();
    void add_product_storage();


    void case_clothes_qt(string *type, string *brand, string *color, string *size_c, int *new_quantity);
    //search - arquivo
    //change - arquivo
    //void case_shoes_qt();
    //search - arquivo
    //change - arquivo
    //void case_sunglasses_qt();
    //search - arquivo
    //change - arquivo
    void change_product_quantity();


    void case_clothes_prc(string *type, string *brand, string *color, string *size_c, double *new_price);
    //search - arqv
    //change - arqv
    void case_shoes_prc(string *type, string *brand, string *color, int *size_s, double *new_price);
    //search - arqv
    //change - arqv
    void case_sunglasses_prc(string* brand, string* color, double* new_price);
    //search - arqv
    //change - arqv
    void change_product_price();


    //void case_clothes_rmv()
    //search - arqv
    //remove - arqv
    //void case_shoes_rmv()
    //remove - arqv
    //change - arqv
    //void case_sunglasses_rmv()
    //search - arqv
    //remove - arqv    
    void remove_product();


    //show_clothes() - arqv
    //show_shoes() - arqv
    //show_sunglasses() - arqv
    void show_storage();




};

#endif // ADMIN_H_PDS
