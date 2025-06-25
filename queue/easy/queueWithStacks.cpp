class MyQueue
{
public:
    stack<int> first, second;
    MyQueue()
    {
    }

    void push(int x)
    {
        first.push(x);
    }

    int pop()
    {
        if (second.empty())
        {
            while (!first.empty())
            {
                int popped = first.top();
                second.push(popped);
                first.pop();
            }
        }
        int popped = second.top();
        second.pop();
        return popped;
    }

    int peek()
    {
        if (second.empty())
        {
            while (!first.empty())
            {
                int topped = first.top();
                second.push(topped);
                first.pop();
            }
        }
        return second.top();
    }

    bool empty()
    {
        return first.empty() && second.empty();
    }
};