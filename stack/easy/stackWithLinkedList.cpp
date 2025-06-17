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

class Stack
{
private:
    Node *topNode;

public:
    Stack()
    {
        topNode = nullptr;
    }

    void push(int x)
    {
        Node *newNode = new Node(x);
        newNode->next = topNode;
        topNode = newNode;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        Node *temp = topNode;
        int poppedVal = temp->data;
        topNode = topNode->next;
        delete temp;
        return poppedVal;
    }

    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return topNode->data;
    }

    bool isEmpty()
    {
        return topNode == nullptr;
    }

    int size()
    {
        int count = 0;
        Node *curr = topNode;
        while (curr != nullptr)
        {
            count++;
            curr = curr->next;
        }
        return count;
    }
};

int main()
{
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top() << endl; // Output: 30
    cout << "Stack size: " << s.size() << endl; // Output: 3

    cout << "Popped: " << s.pop() << endl;  // Output: 30
    cout << "New top: " << s.top() << endl; // Output: 20

    while (!s.isEmpty())
    {
        cout << "Popped: " << s.pop() << endl;
    }

    s.pop(); // Should trigger "Stack Underflow"

    return 0;
}
