#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};

Node *insertAtHead(vector<int> arr)
{
    Node *head = NULL;
    for (int i = 0; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i]);
        newNode->next = head;
        head = newNode;
    }
    return head;
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteNodeAtPosition(Node *head, int index)
{
    if (head == nullptr || index < 1)
        return;

    if (index == 1)
    { // delete head
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    else
    {
        Node *temp = head;
        for (int i = 1; i < index - 1; i++)
        {
            if (temp == nullptr || temp->next == nullptr)
                return; // Out of bounds
            temp = temp->next;
        }
        Node *toDelete = temp->next;
        if (toDelete == nullptr)
            return; // Nothing to delete
        temp->next = toDelete->next;
        delete toDelete;
    }
}

int main()
{
    // your code goes here
    vector<int> arr = {
        5,
        4,
        3,
        2,
        1};
    Node *head;
    head = insertAtHead(arr);
    printList(head);
    deleteNodeAtPosition(head, 5);
    printList(head);
}