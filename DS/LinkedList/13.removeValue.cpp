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
        cout << curr->data;
        curr = curr->next;
    }
}

Node *addElement(vector<int> arr)
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

Node *removeElement(int val, Node *head)
{
    while (head != nullptr && head->data == val)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    Node *temp = head;
    while (temp != nullptr && temp->next != nullptr)
    {
        if (temp->next->data == val)
        {
            Node *curr = temp->next;
            temp->next = temp->next->next;
            delete curr;
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}
int main()
{
    // your code goes here
    vector<int> arr = {1, 1, 3, 4, 5, 6};
    Node *head = addElement(arr);
    head = removeElement(1, head);
    print(head);
}
