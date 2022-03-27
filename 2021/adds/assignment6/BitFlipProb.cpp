#include "BitFlipProb.h"
#include <random>
#include <time.h>

BitFlipProb::BitFlipProb(double i) {
    p = i;
}

BitFlipProb::~BitFlipProb() {}

double BitFlipProb::randomProb() {
    std::mt19937 Random;
    Random.seed(std::random_device()());
    std::uniform_real_distribution<double> randnum(0,1);
    double num = randnum(Random);
    return num;
}

Individual* BitFlipProb::mutate(Individual* i, int j) {
    int length = i->getLength();
    for(int o=0; o<length ; o++) {
        i[o] = randomProb();
    }
    return i;
}