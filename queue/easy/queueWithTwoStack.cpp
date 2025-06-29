/*
    Queue using Two Stacks (Push-Costly)

    ✅ Idea:
    - Use s1 as the main stack (front of queue is top of s1)
    - On push:
      - Push new element to s2
      - Move all of s1 into s2
      - Swap s1 and s2

    ✅ Time Complexity:
    - push(): O(n)
    - pop():  O(1)
    - front(): O(1)

    📌 This version is good when pop/front are more frequent
*/

#include <iostream>
#include <stack>
using namespace std;

class Queue
{
private:
    stack<int> s1, s2;

public:
    // Enqueue element (costly push)
    void push(int x)
    {
        // Step 1: Push to s2
        s2.push(x);

        // Step 2: Move all elements from s1 to s2
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        // Step 3: Swap stacks
        swap(s1, s2);
    }

    // Dequeue element
    void pop()
    {
        if (s1.empty())
        {
            cout << "Queue is empty\n";
            return;
        }
        s1.pop();
    }

    // Return front element
    int front()
    {
        if (s1.empty())
        {
            cout << "Queue is empty\n";
            return -1;
        }
        return s1.top();
    }

    // Check if queue is empty
    bool empty()
    {
        return s1.empty();
    }
};

int main()
{
    Queue q;

    // Test push
    q.push(10);
    q.push(20);
    q.push(30);

    // Test front
    cout << "Front element: " << q.front() << endl; // Should be 10

    // Test pop
    q.pop();

    cout << "Front element after 1 pop: " << q.front() << endl; // Should be 20

    q.pop();
    cout << "Front element after 2 pops: " << q.front() << endl; // Should be 30

    q.pop();

    // Try popping from empty queue
    q.pop(); // Should print: Queue is empty

    return 0;
}
