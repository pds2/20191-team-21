#include "storage_warehouse.h"


Warehouse::Warehouse()
    : Storage() {}


Warehouse::Warehouse(string file_address)
    : Storage() {
    
    Warehouse::load_db(file_address);

}

void Warehouse::load_db(string file_address){

}

void Warehouse::save_db(){

}