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

Node *insertAtKPosition(Node *head, int val, int k)
{
    if (head == NULL)
    {
        if (k == 1)
        {
            return new Node(val);
        }
        else
        {
            return head;
        }
    }
    if (k == 1)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        return newNode;
    }
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        if (count == (k - 1))
        {
            Node *newNode = new Node(val);
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
    vector<int> arr = {1, 2, 3, 4};

    Node *head = convertToLinkedList(arr);
    head = insertAtKPosition(head, 8, 3);
    printList(head);
}