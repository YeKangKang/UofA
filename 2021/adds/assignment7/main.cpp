#include <iostream>
#include "Sort.h"
#include "BubbleSort.h"
#include "QuickSort.h"
#include "RecursiveBinarySearch.h"
#include <vector>
#include <string>
#include <sstream>
using namespace std;
int main() {
    vector<int> vec;
    string s;
    getline(cin, s);
    stringstream is(s);


    stringstream ss(s);

    for(int i = 0; ss >> i; ) {
        vec.push_back(i);
    }
    QuickSort q;
    q.sort(vec);

    RecursiveBinarySearch* B = new RecursiveBinarySearch();
    int k = B->search (vec, 1);
    if(k == false){
        std::cout << "false" << " ";
    }else {
        std::cout << "true" << " ";
    }

    
    for (int i = 0; i < (int)vec.size(); i++) {
        std::cout << vec[i] << " ";
    }

    return 0;
}
