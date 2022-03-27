#include "QuickSort.h"
using namespace std;

vector<int> sorthelp(vector<int> &Arr, int a, int b) {
    int i=a;
    int j=b; 
    if(a<b) {
       int x = Arr[a];
        while (i < j) {

            while(i < j && Arr[j] >= x) {     // loop unt
                j--;
            }
            Arr[i] = Arr[j];

            while(i < j && Arr[i] <= x) {
                i++;
                Arr[j] = Arr[i];
            }
        }
        Arr[i] = x;

        sorthelp(Arr, a, j - 1);
        sorthelp(Arr, j + 1, b);
    }
    return Arr;
}

vector<int> QuickSort::sort(vector<int> list) {
    return sorthelp(list, 0, (int)list.size()-1);
}