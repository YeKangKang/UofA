#include <iostream>
using namespace std;

// sumOfSquare help function
int sumOfSquareHelp(int n, int acc) {
    // base case
    if (n == 1) {
        return acc+1;
    }

    acc += n*n;
    return sumOfSquareHelp(n-1, acc);
}

int sumOfSquare(int n) {
    // error handle for n<=0
    if (n <= 0) {
        return 0;
    }

    int accer = 0;                          // accumulater
    return sumOfSquareHelp(n, accer);       // tail recursive
}
