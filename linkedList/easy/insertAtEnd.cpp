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

Node* insertAtEnd(Node* head, int val) {
    Node* newNode = new Node(val);
    if(head == nullptr) {
        return newNode;
    }
    Node* temp = head;
    while(temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

int main() {
	vector<int> arr = {1,2,3,4,5,6};
	Node* head = addElement(arr);
	head = insertAtEnd(head, 55);
    printList(head);
}
