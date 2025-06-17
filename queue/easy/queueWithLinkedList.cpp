#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class Queue
{
private:
    Node *frontNode;
    Node *rearNode;
    int count;

public:
    Queue()
    {
        frontNode = rearNode = nullptr;
        count = 0;
    }

    void enqueue(int x)
    {
        Node *newNode = new Node(x);
        if (rearNode == nullptr)
        {
            frontNode = rearNode = newNode;
        }
        else
        {
            rearNode->next = newNode;
            rearNode = newNode;
        }
        count++;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        Node *temp = frontNode;
        int val = temp->data;
        frontNode = frontNode->next;
        if (frontNode == nullptr)
        {
            rearNode = nullptr;
        }
        delete temp;
        count--;
        return val;
    }

    int front()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return frontNode->data;
    }

    bool isEmpty()
    {
        return frontNode == nullptr;
    }

    int size()
    {
        return count;
    }
};

int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.front() << endl; // 10
    cout << "Queue size: " << q.size() << endl;     // 3

    cout << "Dequeued: " << q.dequeue() << endl; // 10
    cout << "New front: " << q.front() << endl;  // 20

    while (!q.isEmpty())
    {
        cout << "Dequeued: " << q.dequeue() << endl;
    }

    q.dequeue(); // Should show underflow

    return 0;
}
