#include "Individual.h"
#include <vector>
using namespace std;

Individual::Individual(int length) {
    for (int i=0; i<length; i++) {
        binaryString += '0';
    }
}

Individual::Individual(string str) {
    for (int i=0; i<(int)str.length(); i++) {
        binaryString += str[i];
    }
}

Individual::~Individual() {}

string Individual::getString() {
    return binaryString;
}

int Individual::getBit(int pos) {
    return binaryString[pos]-48;
}

void Individual::flipBit(int pos) {
    if (binaryString[pos] =='0') {
        binaryString[pos] = '1';
    }else {
        binaryString = '0';
    }
}

int Individual::getMaxOnes() {
    int temp = 0;
    vector<int> vec;
    
    for (int i=0; i<(int)binaryString.length(); i++){
        if (binaryString[i]=='1') {
            temp++;
            vec.push_back(temp);
        }else {
            temp=0;
            vec.push_back(temp);
        }
    }
    // return result
    int result = vec[0];
    for (int i=0; i<(int)vec.size(); i++) {
        if (result<vec[i]) {
            result = vec[i];
        }
    }
    return result;
}

int Individual::getLength() {
    return binaryString.length();
}