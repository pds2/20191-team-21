#ifndef WAREHOUSE_STORAGE_H_PDS
#define WAREHOUSE_STORAGE_H_PDS

#include "storage.h"

class Warehouse : public Storage {
public:
    Warehouse(string file_address);
    Warehouse();
    void load_db(string file_address);
    void save_db();
};

#endif //WAREHOUSE_STORAGE_H_PDS