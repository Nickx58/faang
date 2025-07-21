#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        next = nullptr;
    }
};

Node *addFront(vector<int> arr)
{
    Node *head = nullptr;
    for (int i = 0; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        temp->next = head;
        head = temp;
    }
    return head;
}

Node *reverse(Node *head)
{
    Node *curr = head;
    Node *prev = nullptr;
    Node *next = nullptr;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
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
    cout << endl;
}
int main()
{
    // your code goes here
    vector<int> arr = {5, 4, 3, 2, 1};
    Node *head = addFront(arr);
    printList(head);
    head = reverse(head);
    printList(head);
}
