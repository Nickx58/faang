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

Node *convertLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
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

Node *insertAtHead(Node *head, int d)
{
    if (head == nullptr)
    {
        return new Node(d);
    }

    Node *newNode = new Node(d);
    newNode->next = head;
    return newNode;
}

Node *insertAtEnd(Node *head, int d)
{
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }

    Node *newNode = new Node(d);
    temp->next = newNode;
    return head;
}

Node *insertAtK(Node *head, int d, int k)
{
    if (k == 1)
    {
        return insertAtHead(head, d);
    }
    int count = 0;
    Node *temp = head;
    while (temp)
    {
        count++;
        if (count == k - 1)
        {
            Node *newNode = new Node(d);
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}
int main()
{
    // your code goes here
    vector<int> arr = {2, 4, 6, 8, 7};
    Node *head = convertLL(arr);
    printList(head);
    cout << endl;
    head = insertAtK(head, 55, 6);
    printList(head);
}
