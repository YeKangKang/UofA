#ifndef BITFLIPPROB_H
#define BITFLIPPROB_H
#include "Mutator.h"

class BitFlipProb : public Mutator {
private:
    double p;
public:
    BitFlipProb(double prob);
    ~BitFlipProb();
    double randomProb();
    Individual* mutate(Individual* i, int j);
};
#endif