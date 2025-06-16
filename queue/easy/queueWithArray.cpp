#include <iostream>
using namespace std;

class Queue
{
    int *arr;
    int frontIdx;
    int rearIdx;
    int size;
    int capacity;

public:
    Queue(int cap = 100)
    {
        capacity = cap;
        arr = new int[capacity];
        frontIdx = 0;
        rearIdx = 0;
        size = 0;
    }

    ~Queue()
    {
        delete[] arr;
    }

    void enqueue(int x)
    {
        if (size == capacity)
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        arr[rearIdx] = x;
        rearIdx = (rearIdx + 1) % capacity;
        size++;
    }

    int dequeue()
    {
        if (size == 0)
        {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        int val = arr[frontIdx];
        frontIdx = (frontIdx + 1) % capacity;
        size--;
        return val;
    }

    int front()
    {
        if (size == 0)
        {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return arr[frontIdx];
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }
};

int main()
{
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Front element: " << q.front() << endl; // 10

    cout << "Dequeued: " << q.dequeue() << endl; // 10
    cout << "New Front: " << q.front() << endl;  // 20

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70); // Should trigger overflow

    while (!q.isEmpty())
    {
        cout << "Dequeued: " << q.dequeue() << endl;
    }

    q.dequeue(); // Should trigger underflow

    return 0;
}
