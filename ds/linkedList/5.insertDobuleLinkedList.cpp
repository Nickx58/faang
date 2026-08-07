#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

public:
    Node(int d)
    {
        data = d;
        next = nullptr;
        prev = nullptr;
    }
};

Node *convertADD(vector<int> &arr)
{
    Node *head = new Node(arr[0]);

    Node *prev = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        temp->prev = prev;
        prev->next = temp;
        prev = prev->next;
    }
    return head;
}

void print(Node *head)
{
    Node *curr = head;
    while (curr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

Node *insertAtHead(Node *head, int val)
{
    if (head == nullptr)
    {
        Node *newNode = new Node(val);
        return newNode;
    }
    Node *newNode = new Node(val);
    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

Node *insertAtTail(Node *head, int val)
{
    Node *newNode = new Node(val);

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
    newNode->prev = curr;
    return head;
}

int main()
{
    // your code goes here
    vector<int> arr = {1, 3, 2, 4, 5, 6};
    Node *head = convertADD(arr);
    head = insertAtHead(head, 8);
    print(head);
    cout << endl;
    head = insertAtTail(head, 17);
    print(head);
}
