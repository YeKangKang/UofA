#include "PaperDoll.h"
#include <iostream>

PaperDoll::PaperDoll() {
    index = 0;
    five_count = 0;
    arr[0] = 'P';
    arr[1] = 'S';
    arr[2] = 'S';
}

PaperDoll::~PaperDoll() {

}

char PaperDoll::makeMove() {

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