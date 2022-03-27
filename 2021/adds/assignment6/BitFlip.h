#ifndef BITFLIP_H
#define BITFLIP_H
#include "Mutator.h"

class BitFlip : public Mutator {
public:
    BitFlip() {};
    ~BitFlip() {};
    Individual* mutate(Individual* i, int j);
};
#endif