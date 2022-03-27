#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "MapGeneric.h"
#include "MapTriple.h"
#include "MapSquare.h"
#include "MapAbsoluteValue.h"
#include "FilterForTwoDigitPositive.h"
#include "FilterGeneric.h"
#include "FilterNonPositive.h"
#include "FilterOdd.h"
#include "ReduceGeneric.h"
#include "ReduceMinimum.h"
#include "ReduceGCD.h"

using namespace std;

int main() {
    vector<int> a;
    vector<int> result1;
    vector<int> result2;
    int min = 0;
    int gcd = 0;

    //接受输入
    string s;
    getline(cin, s);
    istringstream is(s);
    int inter;
    char ch;
    while (is >> inter) {
        a.push_back(inter);
        is >> ch;
    }

    MapTriple Tri;
    result1 = Tri.map(a);

    MapAbsoluteValue Abs;
    result1 = Abs.map(result1);

    FilterForTwoDigitPositive Tdp;      //?
    result2 = Tdp.filter(result1);

    FilterOdd Odd;
    result2 = Odd.filter(result2);

    ReduceMinimum M;
    min = M.reduce(result2);

    ReduceGCD G;
    gcd = G.reduce(result2);

    cout << min << " " << gcd << endl;



/*
    //input
    cout << "L = ";
    for (int i=0; i<20; i++){
        cout << a[i] << " ";
    }

    cout << endl;

    //L'
    cout << "L' = ";
    for (int i=0; i<20; i++){
        cout << result1[i] << " ";
    }
*/
}