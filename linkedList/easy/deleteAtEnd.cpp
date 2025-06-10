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

Node* deleteAtEnd(Node* head) {
    if(head == NULL || head->next == NULL) {
        return NULL;
    }
    Node* temp = head;
    while(temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

int main() {
	vector<int> arr = {1,2,3,4,5};
	Node* head = addElement(arr);
    cout<<"Before deleting tail"<<endl;
    printList(head);
    cout<<endl;
    cout<<"After deleting tail"<<endl;
    head = deleteAtEnd(head);
    printList(head);
}
