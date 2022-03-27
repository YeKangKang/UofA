#include "LinkedList.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<string> str;
    vector<int> vec;
    int num1 = 0;
    int num2 = 0;
    
    string input;
    string check = "";
    getline(cin,input);
    input=input+" ";
    
   for(int i=0;i<input.size();i++) {
       if(input[i]!=' ') {
            check=check+input[i];
        }
        else if(input[i]==' '&& check!="") {
            str.push_back(check);
            check="";
        }
    }
    
    for(int i=0; i<(int)str.size()-3; i++) {
        vec.push_back(stoi(str[i]));
    }
    
    num1=stoi(str[(int)str.size() - 2]);
    num2=stoi(str[(int)str.size() - 1]);
    
    int array[(int)vec.size()];
    for(int i=0;i<(int)vec.size();i++) {
        array[i]=vec[i];
    }
    
    LinkedList* list = new LinkedList(array,(int)vec.size());
    
    string mt = " ";
    mt = str[(int)str.size()-3];

    /*switch (mt) {
        case "AF":
            list->addFront(num1);
            break;
        case "AE":

    }*/



    if(mt=="AF") {
        list->addFront(num1);
    }
    else if(mt=="AE") {
        list->addEnd(num1);
    }
    else if(mt=="AP") {
        list->addAtPosition(num1,num2);
    }
    else if(mt=="DF") {
        list->deleteFront();
    }
    else if(mt=="DE") {
        list->deleteEnd();
    }
    else if(mt=="DP") {
        list->deletePosition(num1);
    }
    else if(mt=="GI") {
        cout<<(list->getItem(num1))<<" ";
    }
    else if(mt=="S") {
        cout<<(list->search(num1))<<" ";
    }
        
    list->printItems();
    free(list);

    return 0;
}
