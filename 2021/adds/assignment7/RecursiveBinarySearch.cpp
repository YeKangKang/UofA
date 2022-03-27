#include "RecursiveBinarySearch.h"
using namespace std;

int Bsearch(vector<int> a, const int b, int c, int d) {
    if(c>d) {
        return -1;
    }
    int e=(c+d)/2;
    if (a[e]==b) {
        return e;
    }
    else if(b > a[e]) {
        return Bsearch(a, b, e+1, d);
    }
    else {
        return Bsearch(a, b,c, e-1);
    }
}

bool RecursiveBinarySearch::search(vector<int> a, int b) {
    if (Bsearch(a, b, 0, (int)a.size()-1) == -1) {
        return false;
    }
    else {
        return true;
    }
}