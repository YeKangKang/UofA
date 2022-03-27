#include "EfficientTruckLoads.h"
#include <vector>

using namespace std;

EfficientTruckloads::EfficientTruckloads() {}
EfficientTruckloads::~EfficientTruckloads() {}

int EfficientTruckloads::numTrucks(int numCrates, int loadSize) {
    static vector<int> vec;
    // initialize
    if (vec.empty()) {
        for (int i=0; i<numCrates; i++) {
            vec.push_back(-1);
        }
    }

    if (numCrates <= loadSize) {
        return 1;
    }

    // only run one of Odd Or Even
    // odd
    if (numCrates%2 != 0){
        int num1 = vec.at(numCrates/2-1);       // even index ([1] second)
        int num2 = vec.at(numCrates/2);         // odd index ([2] third)
        if (num1 == -1){
            num1 = numTrucks(numCrates/2, loadSize);
            vec.at(numCrates/2-1) = num1;
        }
        if (num2 == -1) {
            num2 = numTrucks(numCrates/2+1, loadSize);
            vec.at(numCrates/2) = num2;
        }
        return num1 + num2;
    }

    // even
    if (numCrates%2 == 0) {
        int num = vec.at(numCrates/2-1);        // even index
        if (num == -1) {
            num = numTrucks(numCrates/2, loadSize);
            vec.at(numCrates/2-1) = num;
        }
        return num*2;
    }

    return -1;
}