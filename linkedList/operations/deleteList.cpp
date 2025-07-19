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

void deleteList(Node *&head)
{
    while (head != nullptr)
    {
        Node *temp = head->next;
        delete head;
        head = temp;
    }
    head = nullptr;
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    // your code goes here
    vector<int> arr = {1, 3, 4, 5, 6, 9};
    Node *head;
    head = insertAtHead(arr);
    deleteList(head);
    if (head == nullptr)
    {
        cout << "List is empty";
    }
    else
    {
        printList(head);
    }
}
