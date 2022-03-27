void DeleteDuplicates(){
    Node* head;
    Node* nextNode;
    Node* newHead;
    nextNode = head -> next;

    while (head -> data != nextNode -> data) {

        if (nextNode -> next != NULL && head -> data != nextNode->data) {
            nextNode -> next = nextNode;
        }
        else {
            head -> data = NULL;
            newHead = head -> next;     // point to next
            head -> next = NULL;
            DeleteDuplicates();
        }
    }
    return;
}
