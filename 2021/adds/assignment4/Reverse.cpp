#include "Reverse.h"
#include <string>

using namespace std;

Reverse::Reverse() {

}

Reverse::~Reverse() {

}

string Reverse::reverseString(string letters) {
    static string result;
    static unsigned int cout = 0;           // ++ in each recursion

    // base case
    if (cout == letters.length()) {
        return result;
    }else {
        result += letters[letters.length()-cout-1];
        cout++;
        return reverseString(letters);
    }
}

int Reverse::reverseDigit(int value) {
    static int result = 0;
    // base case
    if (value != 0) {
        result = result*10 + value%10;
        value /= 10;
        return reverseDigit(value);
    }else {
        return result;
    }
}