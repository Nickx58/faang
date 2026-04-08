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

Node *arrayToLL(vector<int> arr)
{
    Node *newNode = new Node(arr[0]);
    Node *curr = newNode;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        curr->next = temp;
        curr = temp;
    }
    return newNode;
}
int main()
{
    // your code goes here
    vector<int> arr = {1, 2, 3, 4, 7};

    Node *head = arrayToLL(arr);
    Node *cc = head;
    while (cc != nullptr)
    {
        cout << cc->data << " ";
        cc = cc->next;
    }
}
