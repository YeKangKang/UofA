#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList() {
    head = NULL;
    length = 0;
}

LinkedList::LinkedList(int a[], int size) {
    head = NULL;
    length = 0;

    for(int i=0; i<size; i++) {
       
        addEnd(a[i]);
    }
    length=size;
}

LinkedList::~LinkedList() {
    for(int i=0; i<length; i++) {
        deleteFront();
    }
}

void LinkedList::addFront(int item) {
    Node * p1 = new Node;
    p1->data = item;
    p1->next = head;
    head = p1;                  // set head as added var
    if(length<=1) {
        end = p1;
    }
    length++;
}

void LinkedList::addEnd(int item) {
    Node * p1 = new Node;
    p1->data = item;
    p1->next = NULL;
    if(length==1) {
        head->next = p1;
        end = p1;
    }
    else if(length==0) {
        head = p1;
        end = p1;
    }else {
        end->next = p1;
        end = p1;
    }

    length++;
} 


void LinkedList::addAtPosition(int position, int item) {
    if(position<1) {
        addFront(item);
    }
    else if(position>length) {
        addEnd(item);
    }else {
        Node * p1 = new Node;
        p1->data = item;
        position = position-1;
        Node * left;
        Node * right;
        left = head;
        right = head;
    
        for(int i=0; i<position-1; i++) {
            left = left->next;
        }
    
        for(int i=0; i<position; i++) {
            right = right->next;
        }
    
        p1->next = right;
        left->next = p1;
        length++;
    }
} 

int LinkedList::search(int item) {
    Node * n;
    n=head;
    for(int i=0; i<length; i++) {
        if((n->data)!=item) {
            n = n->next;
        }
        else if((n->data)==item) {
            return i+1;
        }
    }
        
} 

void LinkedList::deleteFront() {
    Node * a = head;
    head = head->next;
    delete a;
    length--;
} 

void LinkedList::deleteEnd() {
    Node * a = end;
    Node * b = head;
    for(int i=0; i<length-2; i++) {
        b = b->next;
    }
    end = b;
    delete a;
    length--;
} 

void LinkedList::deletePosition(int position) {
    Node * left;
    Node * right;
    position = position-1; 

    left = head;
    right = head;
    if(position>length-1){
        cout << "outside range";
    }
    else if(position<0) {
        cout << "outside range";
    }else {
      for(int i=0; i<position-1; i++) {
        left = left->next;
      }
      for(int i=0; i<position+1; i++) {
        right = right->next;
      }
      if(position==1-1) {
        deleteFront();
      }else {
        delete left->next; 
        left->next = right;
        length--;
      }
    }

} 

int LinkedList::getItem(int position) {
    int out;
    Node * a = head;
    for(int i=0; i<position-1; i++) {
        a=a->next;
    }
    out = a->data;
    return out;

} 

void LinkedList::printItems() {
    int i=1;
    Node * newhead = head;
    while(newhead) {
        if(i!=length) {
            cout << newhead->data << " ";
            newhead = newhead->next;
            i++;
        }
        else if(i==length) {
            cout << newhead->data << endl;
            break;
        }
    }
    
} 