#include "TruckLoads.h"
using namespace std;

Truckloads::Truckloads() {}

Truckloads::~Truckloads() {}

int Truckloads::numTrucks(int numCrates, int loadSize) {
    // base case
    if (numCrates <= loadSize) {
        return 1;
    }else if (numCrates%2==0) {
        return numTrucks(numCrates/2, loadSize)+numTrucks(numCrates/2, loadSize);
    }
    return numTrucks(numCrates/2, loadSize)+numTrucks(numCrates/2+1,loadSize);
}