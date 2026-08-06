#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node *convertToLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = mover->next;
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
}

Node *insertAtHead(Node *head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    return newNode;
}

Node *insertAtEnd(Node *head, int val)
{
    Node *newNode = new Node(val);
    if (head == nullptr)
    {
        return newNode;
    }

    Node *curr = head;

    while (curr->next)
    {
        curr = curr->next;
    }

    curr->next = newNode;
    return head;
}

Node *insertAtKthPosition(Node *head, int val, int k)
{
    Node *newNode = new Node(val);

    if (k == 1)
    {
        newNode->next = head;
        return newNode;
    }
    int count = 1;
    Node *curr = head;
    while (curr && count < k - 1)
    {
        curr = curr->next;
        count++;
    }

    if (curr == nullptr)
    {
        delete newNode;
        return head;
    }
    newNode->next = curr->next;
    curr->next = newNode;
    return head;
}

int main()
{
    // your code goes here
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    Node *head = convertToLL(arr);
    print(head);
    cout << endl
         << "Insert at head" << endl;
    head = insertAtHead(head, 100);
    print(head);
    cout << endl
         << "Insert at End" << endl;
    head = insertAtEnd(head, 18);
    print(head);
    cout << endl
         << "Insert at kth position" << endl;
    head = insertAtKthPosition(head, 17, 3);
    print(head);
}
