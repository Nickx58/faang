/*
    Stack using Single Queue (Push-Costly)

    ✅ Idea:
    - Always keep the newest pushed element at the front of the queue

    ✅ push(x):
    1. Enqueue x
    2. Rotate the queue: move previous elements to the back
       so that x becomes the front (top of stack)

    ✅ pop() = q.pop()
    ✅ top() = q.front()
    ✅ empty() = q.empty()

    ✅ Time Complexity:
    - push(): O(n)
    - pop():  O(1)
    - top():  O(1)

    📌 Great when pop/top are frequent
*/

#include <iostream>
#include <queue>
using namespace std;

class Stack
{
private:
    queue<int> q1;

public:
    // Push element to the stack (costly)
    void push(int x)
    {
        q1.push(x);
        int size = q1.size();

        // Rotate the queue to move the new element to the front
        for (int i = 0; i < size - 1; i++)
        {
            int temp = q1.front();
            q1.pop();
            q1.push(temp);
        }
    }

    // Removes the top element
    void pop()
    {
        if (q1.empty())
        {
            cout << "Stack is empty\n";
            return;
        }
        q1.pop();
    }

    // Returns the top element
    int top()
    {
        if (q1.empty())
        {
            cout << "Stack is empty\n";
            return -1;
        }
        return q1.front();
    }

    // Returns whether the stack is empty
    bool empty()
    {
        return q1.empty();
    }
};

int main()
{
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top() << endl; // 30

    s.pop();
    cout << "Top after pop: " << s.top() << endl; // 20

    s.pop();
    s.pop();

    cout << "Is empty? " << (s.empty() ? "Yes" : "No") << endl;

    return 0;
}