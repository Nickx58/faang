/*
Behaviour of queue
every item pushed to the front. So linked list we will push at the head evertime;
Pop -> delete the current head;
empty -> check the count
front -> head->data;
*/

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Queue
{
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = rear = NULL;
    }

    void enqueue(int x)
    {
        Node *temp = new Node();
        temp->data = x;
        temp->next = NULL;

        if (rear == NULL)
        {
            front = rear = temp;
            return;
        }

        rear->next = temp;
        rear = temp;
    }

    void dequeue()
    {
        if (front == NULL)
        {
            cout << "Queue is empty\n";
            return;
        }

        Node *temp = front;
        front = front->next;

        if (front == NULL)
            rear = NULL;

        delete temp;
    }

    void display()
    {
        Node *temp = front;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display(); // 10 20 30
    q.dequeue();
    q.display(); // 20 30
}
