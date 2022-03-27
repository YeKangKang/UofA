#ifndef NODE_H
#define NODE_H

class Node{
    public:
        int data;
        Node* next;

        Node();
        Node(int a, Node* b);
        ~Node();

        int getData();
        Node* GetNext();
};

#endif