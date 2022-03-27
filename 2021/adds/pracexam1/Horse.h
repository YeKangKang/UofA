#ifndef HORSE_H
#define HORSE_H
#include "Transport.h"

class Horse : public Transport {
public:
    Horse();
    ~Horse();
    void go();
};

#endif