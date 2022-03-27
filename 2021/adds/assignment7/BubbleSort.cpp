#include "BubbleSort.h"
using namespace std;

vector<int> BubbleSort::sort(vector<int> list) {
    for (int i=0; i<(int)list.size()-1; i++) {
        int k=0;
        for (int j=0; j<(int)list.size()-i; j++) {
            if(list[j] > list[j+1]) {
                int temp = list[j+1];
                list[j+1] = list[j];
                list[j] = temp;
                k=1;
            }else {
                k=0;
            }
        }
        if(k==0) {
            return list;
        }
    }
    return list;
}
