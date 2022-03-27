#include "Rearrange.h"

Individual *Rearrange::mutate(Individual *i, int j) {
    std::string str1;
    std::string str2;
    str1 = i->getString().erase(0, j - 1);
    str2 = i->getString().substr(0, j - 1);

    Individual* res = new Individual(str1.append(str2));
    return res;
}