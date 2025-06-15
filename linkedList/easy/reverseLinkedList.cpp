Node* reverseList(Node* head) {
    if(head == nullptr) {
        return head;
    }
    
    Node* prev = NULL;
    Node* curr = head;
    
    while(curr != NULL) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}