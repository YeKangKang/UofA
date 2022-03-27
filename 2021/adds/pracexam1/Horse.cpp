#include "Horse.h"
#include <iostream>
using namespace std;

Horse::Horse() {
    dist = 0;
}

Horse::~Horse() {

}

void Horse::go() {
    dist += 100;
}