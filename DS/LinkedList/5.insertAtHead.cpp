#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

Node *convertToLinkedList(vector<int> arr)
{
    Node *head = new Node(arr[0]);

    Node *curr = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        curr->next = temp;
        curr = temp;
    }
    return head;
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node *insertAtHead(Node *head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    return newNode;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};

    Node *head = convertToLinkedList(arr);
    head = insertAtHead(head, 8);
    printList(head);
}