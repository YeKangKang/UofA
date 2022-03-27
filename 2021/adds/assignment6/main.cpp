#include "Individual.h"
#include "BitFlip.h"
#include "BitFlipProb.h"
#include "Rearrange.h"

#include <iostream>
using namespace std;

Individual* execute(Individual* iptr, Mutator* mptr, int i) {
    return mptr->mutate(iptr, i);
}

int main() {
    string binarystr1;
    string binarystr2;
    int k1;
    int k2;
    cin >> binarystr1 >> k1 >> binarystr2 >> k2;
    
    Individual* i1 = new Individual(binarystr1);
    Individual* i2 = new Individual(binarystr2);
    BitFlip* M1 = new BitFlip();
    Rearrange* M2 = new Rearrange();
    
    Individual* a = execute(i1,M1,k1);
    Individual* b = execute(i2,M2,k2);

    cout << a->getString() << " " << b->getString() << " " << b->getMaxOnes() << endl;
}