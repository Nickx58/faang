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

Node *deleteHead(Node *head)
{
    if (head == nullptr)
        return nullptr;
    Node *temp = head;
    temp = head->next;
    delete head;
    return temp;
}

// delete tail
Node *deleteTail(Node *head)
{
    if (head == nullptr)
        return nullptr;

    // Only one node
    if (head->next == nullptr)
    {
        delete head;
        return nullptr;
    }
    Node *curr = head;
    while (curr->next && curr->next->next)
    {
        curr = curr->next;
    }
    // now curr will point to 2nd last node;
    Node *temp = curr->next;
    delete temp;
    curr->next = nullptr;
    return head;
}

Node *deleteKthElement(Node *head, int k)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    int count = 1;
    Node *curr = head;
    while (curr != nullptr && count < k - 1)
    {
        curr = curr->next;
        count++;
    }
    if (curr == nullptr || curr->next == nullptr)
        return head;
    Node *temp = curr->next;
    curr->next = temp->next;
    delete temp;
    return head;
}

int main()
{
    // your code goes here
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    Node *head = convertToLL(arr);
    print(head);
    cout << endl
         << "Delete Head" << endl;
    head = deleteHead(head);
    print(head);
    cout << endl
         << "Delete Tail" << endl;
    head = deleteTail(head);
    print(head);
    cout << endl
         << "Delete kth element" << endl;
    head = deleteKthElement(head, 3);
    print(head);
}
