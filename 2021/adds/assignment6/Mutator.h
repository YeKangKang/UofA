#ifndef MUTATOR_H
#define MUTATOR_H
#include "Individual.h"

class Mutator {
public:
    Mutator();
    ~Mutator();
    virtual Individual* mutate(Individual* i, int j) = 0;
};
#endif