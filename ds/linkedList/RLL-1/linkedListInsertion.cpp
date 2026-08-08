#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int d)
    {
        data = d;
        next = nullptr;
    }
};

void print(Node *head)
{
    Node *curr = head;
    while (curr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

Node *convert(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *curr = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i]);
        curr->next = newNode;
        curr = curr->next;
    }
    return head;
}

Node *insertAtHead(Node *head, int d)
{
    Node *newNode = new Node(d);
    newNode->next = head;
    return newNode;
}

Node *insertAtEnd(Node *head, int d)
{
    Node *newNode = new Node(d);
    if (head == nullptr)
    {
        return newNode;
    }

    Node *curr = head;
    while (curr->next)
    {
        curr = curr->next;
    }

    curr->next = newNode;
    return head;
}

Node *insertAtKth(Node *head, int d, int k)
{
    // Insert at beginning
    if (k == 1)
    {
        return insertAtHead(head, d);
    }
    // Invalid position
    if (head == nullptr || k <= 0)
    {
        return head;
    }

    int count = 1;
    Node *curr = head;
    while (curr != nullptr && count < k - 1)
    {
        curr = curr->next;
        count++;
    }
    if (curr == nullptr)
    {
        return head;
    }
    Node *newNode = new Node(d);
    newNode->next = curr->next;
    curr->next = newNode;
    return head;
}
int main()
{
    // your code goes here
    vector<int> arr = {1, 2, 3, 4};
    Node *head = convert(arr);
    print(head);
    cout << "Insert At Head" << endl;
    head = insertAtHead(head, 55);
    print(head);
    cout << "Insert At End" << endl;
    head = insertAtEnd(head, 155);
    print(head);
    cout << "Insert At kth" << endl;
    head = insertAtKth(head, 8, 3);
    print(head);
}
