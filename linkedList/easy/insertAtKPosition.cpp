#include <bits/stdc++.h>

using namespace std;

class Node {
    public: int data;
    Node * next;

    public: Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

void printList(Node* head) {
    Node* temp = head;
    
    while(temp != nullptr) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

Node* insertAtKPosition(Node* head, int val, int k) {
    if(head == NULL) {
        if(k == 1) {
            Node* newNode = new Node(val);
            newNode->next = NULL;
            return newNode;
        } else {
            return head;
        }
    }
    if(k == 1) {
        Node* newNode = new Node(val);
        newNode->next = head;
        return newNode;
    }
    Node* temp = head;
    int count = 0;
    while(temp != NULL) {
        count++;
        if(count == (k-1)) {
            Node* newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}

int main() {
    Node* head = insertAtKPosition(head, 5, 1);
    head = insertAtKPosition(head,4,2);
    head = insertAtKPosition(head,3,3);
    head = insertAtKPosition(head,2,4);
    head = insertAtKPosition(head,55,5);
    printList(head);

}