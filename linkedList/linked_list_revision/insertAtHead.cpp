#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next = nullptr;
    }
};

Node *addElementatHead(Node *head, int d)
{
    Node *newNode = new Node(d);
    newNode->next = head;
    return newNode;
}

void printList(Node *head)
{
    Node *curr = head;

    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

int main()
{
    // your code goes here
    Node *head = nullptr;

    head = addElementatHead(head, 4);
    head = addElementatHead(head, 3);
    head = addElementatHead(head, 2);
    head = addElementatHead(head, 1);

    printList(head);
}
