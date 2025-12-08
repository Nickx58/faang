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

Node *convertToLL(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *curr = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i]);
        curr->next = newNode;
        curr = newNode;
    }

    return head;
}
void print(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node *reverse(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *front = NULL;

    while (curr != NULL)
    {
        front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }
    head = prev;
    return head;
}
int main()
{
    // your code goes here
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = convertToLL(arr);
    print(head);
    cout << endl;
    head = reverse(head);
    print(head);
}
