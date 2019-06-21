#ifndef WAREHOUSE_STORAGE_H_PDS
#define WAREHOUSE_STORAGE_H_PDS

#include "storage.h"
#include <fstream>

class Warehouse : public Storage {
public:
    Warehouse();
    void read_from_db();
    void save_to_db();
};

#endif //WAREHOUSE_STORAGE_H_PDS