#include <stack>
using namespace std;

class MyQueue
{
    stack<int> inStack, outStack;

public:
    MyQueue() {}

    void push(int x)
    {
        inStack.push(x);
    }

    int pop()
    {
        if (outStack.empty())
        {
            while (!inStack.empty())
            {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        int val = outStack.top();
        outStack.pop();
        return val;
    }

    int peek()
    {
        if (outStack.empty())
        {
            while (!inStack.empty())
            {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        return outStack.top();
    }

    bool empty()
    {
        return inStack.empty() && outStack.empty();
    }
};

/*
Approach: Two Stacks (Amortized O(1) Operations)
We use:

inStack: for pushing new elements

outStack: for popping/peeking in FIFO order

✅ Main Idea:
push(x) → just push to inStack

pop() / peek():
    If outStack is empty, move all elements from inStack to outStack
    Then pop/peek from outStack

This ensures queue order (FIFO) is preserved.
*/