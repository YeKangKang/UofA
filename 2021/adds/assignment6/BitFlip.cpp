#include "BitFlip.h"
#include <string>
using namespace std;

Individual* BitFlip::mutate(Individual* i, int j) {
    int L = i->getLength();
    string str = i->getString();

    if(j>L) {
        if (str[(j%L)-1] == '1') {
            str[(j%L)-1] = '0';
        }else {
            str[(j%L)-1] = '1';
        }    
    
    }else {
        if (str[j-1] == '1') {
            str[j-1] = '0';
        }else {
            str[j-1] = '1';
        }   
    }

    // return result
    Individual* res = new Individual(str);
    return res;
}