class MyStack
{
    queue<int> q;

public:
    MyStack() {}

    void push(int x)
    {
        q.push(x);
        for (int i = 1; i < q.size(); ++i)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        int val = q.front();
        q.pop();
        return val;
    }

    int top()
    {
        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }
};

/*
    Explanation for the push
    Approach:
    Use one queue
    Make push() operation simulate stack by rotating the queue

    How push(x) Works:
    Push x to the back of the queue.

    Rotate the queue to bring x to the front:

    Do this by popping all previous elements and pushing them to the back.

    void push(int x) {
    q.push(x);
    int n = q.size();
    for (int i = 1; i < n; ++i) {
        q.push(q.front());
        q.pop();
    }
}

Push elements in order: push(10), push(20), push(30)

After push(10):
Queue: [10] → Top of stack: 10

After push(20):
Queue: [20, 10] → Top of stack: 20

After push(30):
Queue: [30, 20, 10] → Top of stack: 30
*/