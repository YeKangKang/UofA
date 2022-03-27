#include "Node.h"
#include <iostream>
using namespace std;

Node::Node() {
    data=0;
    next=NULL;
}

Node::Node(int a, Node* b){
    data=a;
    next=b;
}

int Node::getData() {
    return data;
}

Node* Node::GetNext() {
    return next;
}

Node::~Node() {}