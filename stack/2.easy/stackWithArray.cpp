#include <bits/stdc++.h>

using namespace std;

class Stack
{
    int top;
    int *arr;
    int size;

public:
    Stack(int s = 100)
    {
        size = s;
        top = -1;
        arr = new int(size);
    }

    void push(int x)
    {
        if (top >= size - 1)
        {
            cout << "Stack overflow";
            return;
        }
        arr[++top] = x;
    }

    int pop()
    {
        if (top == -1)
        {
            cout << "Stack underflow";
            return 0;
        }
        return arr[top--];
    }

    int Top()
    {
        if (top == -1)
        {
            cout << "Stack is empty";
            return 0;
        }
        return arr[top];
    }

    int Size()
    {
        return top + 1;
    }
};

int main()
{
    Stack s(5); // Create a stack of size 5

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.Top() << endl; // Output: 30
    cout << "Stack size: " << s.Size() << endl; // Output: 3

    cout << "Popping element: " << s.pop() << endl; // Output: 30
    cout << "New top: " << s.Top() << endl;         // Output: 20

    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70); // Should trigger "Stack Overflow"

    s.pop(); // Should trigger "Stack Underflow"

    return 0;
}