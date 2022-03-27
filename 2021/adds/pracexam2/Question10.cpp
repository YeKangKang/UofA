#include <iostream>
using namespace std;

int sumOfSquare(int n) {
    // for n<=0 Error handle
    if (n <= 0) {
        return 0;
    }
    // base case
    if (n == 1) {
        return 1;
    }

    return n*n + sumOfSquare(n-1);      // non tail recursion
}
