#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    
    public:
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

Node* addElement(vector<int> arr) {
    Node* head = new Node(arr[0]);
    
    Node* curr = head;
    
    for(int i = 1; i<arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        curr->next = temp;
        curr = temp;
    }
    return head;
}

void printList(Node* head) {
    if(head == nullptr) {
        return;
    }
    cout<<head->data<<" ";
    printList(head->next);
}

Node* deleteKElement(Node* head, int k) {
    if(head == NULL) {
        return head;
    }
    if(k == 1) { // delete head
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    
    int count = 0;
    Node* prev = NULL;
    Node* temp = head;
    while(temp != NULL) {
        count++;
        if(count == k) {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}


int main() {
	vector<int> arr = {1,2,3,4,5,6};
	Node* head = addElement(arr);
    int k = 5;
    head = deleteKElement(head, k);
    printList(head);
}
