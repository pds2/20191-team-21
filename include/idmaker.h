#ifndef IDMAKER_H_PDS
#define IDMAKER_H_PDS

#include <string>
#include <map>
#include <utility>
#include <sstream>
#include <algorithm>

using namespace std;

class IdMaker {
public:
    static string make_id(map<string, string> features);
};

#endif //IDMAKER_H_PDS
