#include "storage_warehouse.h"


Warehouse::Warehouse()
    : Storage() {
        
}

void Warehouse::read_from_db(){
    ifstream in(DB_FILE);
    while (!in.eof()) {
        auto p = Product::read_from(in);
        if  (p->get_id().size() > 3) {
            this->add_product(p);
        }
    }
    in.close();
}

void Warehouse::save_to_db(){
    ofstream out(DB_FILE);
    for (auto& i : this->_storage){
        (this->get_product(i.first))->save_to(out);
    }
    out.close();
}