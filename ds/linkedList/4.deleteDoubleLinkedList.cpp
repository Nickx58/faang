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

Node *convertADD(vector<int> &arr)
{
    Node *head = new Node(arr[0]);

    Node *prev = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        temp->prev = prev;
        prev->next = temp;
        prev = prev->next;
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
    if (head == NULL || head->next == NULL)
    {
        return nullptr;
    }
    Node *prev = head;
    head = head->next;
    head->prev = nullptr;
    prev->next = nullptr;
    delete prev;
    return head;
}

Node *deleteTail(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return nullptr;
    }
    Node *curr = head;

    while (curr->next->next)
    {
        curr = curr->next;
    }

    Node *temp = curr->next;
    curr->next = nullptr;
    temp->prev = nullptr;
    delete temp;
    return head;
}

Node *deleteKElement(Node *head, int k)
{
    if (head == nullptr)
        return nullptr;

    if (k == 1)
        return deleteHead(head);

    int count = 1;
    Node *curr = head;

    while (curr && curr->next && count < k - 1)
    {
        curr = curr->next;
        count++;
    }

    if (curr == nullptr || curr->next == nullptr)
        return head;

    Node *nxt = curr->next;

    curr->next = nxt->next;

    if (nxt->next)
        nxt->next->prev = curr;

    delete nxt;
    return head;
}

int main()
{
    // your code goes here
    vector<int> arr = {1, 3, 2, 4, 5, 6};
    Node *head = convertADD(arr);
    head = deleteKElement(head, 6);
    print(head);
}
