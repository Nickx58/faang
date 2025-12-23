#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node *next;
};

class Stack
{
    Node *top;

public:
    Stack()
    {
        top = NULL; // stack is empty
    }

    // Push operation
    void push(int x)
    {
        Node *newNode = new Node();
        newNode->data = x;
        newNode->next = top;
        top = newNode;
        cout << x << " pushed into stack\n";
    }

    // Pop operation
    void pop()
    {
        if (top == NULL)
        {
            cout << "Stack Underflow\n";
            return;
        }
        Node *temp = top;
        cout << temp->data << " popped from stack\n";
        top = top->next;
        delete temp;
    }

    // Peek operation
    void peek()
    {
        if (top == NULL)
        {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Top element is " << top->data << endl;
    }

    // Display stack
    void display()
    {
        if (top == NULL)
        {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements: ";
        Node *temp = top;
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
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.display();

    s.peek();
    s.pop();
    s.display();

    return 0;
}
