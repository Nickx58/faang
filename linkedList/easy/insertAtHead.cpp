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

Node* insertAtHead(Node* head, int val) {
    Node* new_node = new Node(val);
    new_node->next = head;
    return new_node;
}

void printList(Node* head) {
    Node* temp = head;
    while(temp) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
int main() {
	vector<int> arr = {0,1,2};
	
	Node* head = addElement(arr);
    head = insertAtHead(head, 5);
    printList(head);
}
