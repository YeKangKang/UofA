#ifndef MAPABSOLUTEVALUE_H
#define MAPABSOLUTEVALUE_H
#include "MapGeneric.h"

class MapAbsoluteValue : public MapGeneric {
private:
    int f(int input);
public:
    MapAbsoluteValue();
    ~MapAbsoluteValue();
};

#endif