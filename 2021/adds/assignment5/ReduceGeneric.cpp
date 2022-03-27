#include "ReduceGeneric.h"

using namespace std;

ReduceGeneric::ReduceGeneric() {}

ReduceGeneric::~ReduceGeneric() {}

int ReduceGeneric::reduce(vector<int> arr) {
    static unsigned int num = 0;
    int result = 999;
    if (num==arr.size()-2){
        return result;
    }
    result = binaryOperator(arr[num], arr[num+1]);
    return reduce(arr);
}