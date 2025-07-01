/*
    There can be multiple solution
    one with extra space
    we use helper stack to store the min value while pushing
    2nd the math based approach to store in constant space.

    I will write the both solution

*/

class MinStack
{
public:
    stack<pair<int, int>> st;
    MinStack() {}

    void push(int val)
    {
        if (st.empty())
        {
            st.push({val, val});
        }
        else
        {
            int currentMin = min(st.top().second, val);
            st.push({val, currentMin});
        }
    }

    void pop()
    {
        if (!st.empty())
        {
            st.pop();
        }
    }

    int top()
    {
        if (!st.empty())
        {
            return st.top().first;
        }
        else
        {
            return -1;
        }
    }

    int getMin()
    {
        if (!st.empty())
        {
            return st.top().second;
        }
        else
        {
            return -1;
        }
    }
};

/* -> Above with stack<pair<int,int>> -> It's the expected solution*/

class MinStack
{
public:
    stack<int> s1, s2;
    MinStack() {}

    void push(int val)
    {
        s1.push(val);
        if (!s2.empty())
        {
            int minValue = min(val, s2.top());
            s2.push(minValue);
        }
        else
        {
            s2.push(val);
        }
    }

    void pop()
    {
        s1.pop();
        s2.pop();
    }

    int top() { return s1.top(); }

    int getMin() { return s2.top(); }
};