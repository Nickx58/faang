/*
    Stack using Two Queues (Push-Costly Approach)

    ✅ Concept:
    - We use two queues: q1 (main), q2 (temporary)
    - The idea is to always maintain the newest pushed element at the front of q1,
      so that `q1.front()` gives us the top of the stack (LIFO behavior).

    ✅ Operations:
    1. push(x):
       - Push x into q2
       - Move all elements from q1 to q2 (preserves stack order)
       - Swap q1 and q2
       - Result: q1 contains the new stack (with x at the front/top)

    2. pop():
       - Just do q1.pop() — removes the top element of the stack
       - Time: O(1)

    3. top():
       - Return q1.front() — gives the top element
       - Time: O(1)

    4. empty():
       - Return whether q1 is empty

    ✅ Time Complexities:
    - push(): O(n)   ← because we move all elements from q1 to q2
    - pop():  O(1)
    - top():  O(1)

    ✅ Why does this work?
    - The "reversing" of order is done during push by inserting the new element
      first into q2, and then moving q1's elements behind it.
    - Swapping q1 and q2 doesn't change the element order; it just updates roles.

    🔄 Summary:
    - push is expensive (O(n)) because it rearranges the queue to maintain stack order
    - pop and top are fast (O(1)), ideal for frequent stack operations

    📌 Tip:
    - Use this pattern when pop/top operations are more frequent than push
*/

#include <bits/stdc++.h>

using namespace std;

class Stack
{
private:
    queue<int> q1,
        q2;

public:
    void push(int x)
    {
        q2.push(x);

        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        swap(q1, q2);
    }

    void pop()
    {
        if (q1.empty())
        {
            cout << "Stack is empty\n";
            return;
        }
        q1.pop();
    }

    int top()
    {
        if (q1.empty())
        {
            cout << "Stack is empty\n";
            return -1;
        }
        return q1.front();
    }
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