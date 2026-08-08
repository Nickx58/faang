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
    }
};

Node *deleteHead(Node *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    Node *curr = head;
    head = head->next;
    delete curr;
    return head;
}

Node *deleteTail(Node *head)
{
    if (head == nullptr || head->next == nullptr)
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
    delete temp;
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
        return deleteHead(head);
    }
    int count = 1;
    Node *curr = head;
    while (curr != nullptr && count < k - 1)
    {
        curr = curr->next;
        count++;
    }
    if (curr == nullptr || curr->next == nullptr)
    {
        return nullptr;
    }

    Node *temp = curr->next;
    curr->next = temp->next;
    delete temp;
    return head;
}