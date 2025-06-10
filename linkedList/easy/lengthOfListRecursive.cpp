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

int lengthOfNode(Node* head, int count) {
    if(head == nullptr) {
        return count;
    }
    return lengthOfNode(head->next, count+1);
}

void printList(Node* head) {
    if(head == nullptr) {
        return;
    }
    cout<<head->data<<" ";
    printList(head->next);
}

int main() {
	vector<int> arr = {1,2,3,4,5};
	Node* head = addElement(arr);
    int count = lengthOfNode(head, 0);
    cout<<count<<endl;
    printList(head);
}
