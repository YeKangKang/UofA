#include "FilterGeneric.h"
#include <vector>

using namespace std;

FilterGeneric::FilterGeneric() {}

FilterGeneric::~FilterGeneric() {}

vector<int> FilterGeneric::filter(vector<int> arr) {
    static unsigned int num = 0;
    static vector<int> result;

    if (num==arr.size()) {
        return result;
    }

    if (g(arr[num])) {
        result.push_back(arr[num]);
        num++;
    }else {
        num++;
    }

    return filter(arr);
}