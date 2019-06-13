#ifndef WAREHOUSE_STORAGE_H_PDS
#define WAREHOUSE_STORAGE_H_PDS

#include "storage.h"

class Warehouse : public Storage {
public:
    Warehouse(string file_address);
    void load_db();
    void save_db();

};

#endif //WAREHOUSE_STORAGE_H_PDS