#include "idmaker.h"

std::string IdMaker::make_id(map<string, string> features){
    string key;
    for (const auto& i : features){
        key += i.second;
    }
    transform(key.begin(), key.end(), key.begin(), ::toupper);
    return key;
}