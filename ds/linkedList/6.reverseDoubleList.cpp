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

Node *convert(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *curr = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        curr->next = temp;
        temp->prev = curr;
        curr = curr->next;
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
    cout << endl;
}

Node *reverse(Node *head)
{
    Node *curr = head;
    Node *newHead = nullptr;
    while (curr != nullptr)
    {
        Node *temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        newHead = curr;
        curr = curr->prev;
    }

    return newHead;
}

int main()
{
    // your code goes here
    vector<int> arr = {5, 4, 3, 2, 1};
    Node *head = convert(arr);
    print(head);
    cout << "Reverse" << endl;
    head = reverse(head);
    print(head);
}
