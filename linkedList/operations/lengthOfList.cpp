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

Node *addFromHead(vector<int> arr)
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
}

int lengthOfList(Node *head)
{
    int length = 0;

    Node *curr = head;

    while (curr != nullptr)
    {
        length++;
        curr = curr->next;
    }
    return length;
}

int main()
{
    // your code goes here
    vector<int> arr = {1, 3, 4, 5, 6, 9};
    Node *head;
    head = addFromHead(arr);

    printList(head);
    cout << endl;
    int len = lengthOfList(head);
    cout << "The length of List is: " << len << endl;
}
