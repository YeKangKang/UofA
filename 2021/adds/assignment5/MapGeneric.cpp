#include "MapGeneric.h"

using namespace std;

MapGeneric::MapGeneric() {}

MapGeneric::~MapGeneric() {}

vector<int> MapGeneric::map(vector<int> arr) {
    static int num = arr.size();
    if (num <= 0) {
        return arr;
    }
    arr[num-1] = f(arr[num-1]);
    num--;
    return map(arr);
}