#ifndef MAPGENERIC_H
#define MAPGENERIC_H
#include <vector>

class MapGeneric {
private:
    virtual int f(int input) = 0;
public:
    MapGeneric();
    ~MapGeneric();
    std::vector<int> map(std::vector<int> arr);
};

#endif