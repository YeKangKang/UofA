#include <iostream>
#include "Reverse.h"
#include "TruckLoads.h"
#include "EfficientTruckLoads.h"

using namespace std;

int main() {
    // setup obj
    Reverse R;
    Truckloads T;
    EfficientTruckloads E;

    // setup var;
    int i;
    string s;
    int numCrates;
    int loadSize;

    cin >> i;
    cin >> s;
    cin >> numCrates;
    cin >> loadSize;

    if (i>=0) {
        cout << R.reverseDigit(i) << " ";
    } else {
        cout << "ERROR ";
    }

    cout << R.reverseString(s) << " ";

    if (numCrates>=0 && loadSize>=0) {
        cout << T.numTrucks(numCrates,loadSize) << " ";
        cout << E.numTrucks(numCrates,loadSize) << " ";
    }else {
        cout << "ERROR " << "ERROR";
    }
}