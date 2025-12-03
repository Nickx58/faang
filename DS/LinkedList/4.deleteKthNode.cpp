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

Node *removeKthNode(Node *head, int k)
{
    if (head == NULL)
    {
        return head;
    }
    if (k == 1)
    { // remove head;
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    int count = 0;
    Node *temp = head;
    Node *prev = NULL;

    while (temp != NULL)
    {
        count++;

        if (count == k)
        {
            prev->next = prev->next->next;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};

    Node *head = convertToLinkedList(arr);
    head = removeKthNode(head, 5);
    printList(head);
}