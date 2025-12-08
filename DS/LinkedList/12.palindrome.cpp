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

bool isPalindrome(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return true;
    }

    // find the middle
    Node *slow = head;
    Node *fast = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *slowHead = reverse(slow->next);
    Node *temp = head;
    Node *second = slowHead;

    while (second != NULL)
    {
        if (temp->data != second->data)
        {
            reverse(slowHead);
            return false;
        }
        second = second->next;
        temp = temp->next;
    }
    // reverse(slowHead);
    return true;
}
int main()
{
    // your code goes here
    vector<int> arr = {1, 2, 3, 2, 1};
    Node *head = convertToLL(arr);
    print(head);
    isPalindrome(head) ? cout << "Yes" : cout << "NO";
}
