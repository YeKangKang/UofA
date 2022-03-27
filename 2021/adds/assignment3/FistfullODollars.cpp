#include "FistfullODollars.h"
#include <iostream>

FistfullODollars::FistfullODollars() {
    index = 0;
    five_count = 0;
    arr[0] = 'R';
    arr[1] = 'P';
    arr[2] = 'P';
}

FistfullODollars::~FistfullODollars() {

}

char FistfullODollars::makeMove() {
    if (five_count == 5){
        index = 0;
        five_count = 0;
    }

    if (index == 3) {
        index = 0;
    }

    char result = arr[index];
    index++;
    five_count++;
    return result;
}