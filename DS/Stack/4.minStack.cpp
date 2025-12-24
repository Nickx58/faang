#include <stack>
using namespace std;

class MinStack
{
private:
    stack<long long> st;
    long long minVal;

public:
    MinStack() {}

    void push(int x)
    {
        if (st.empty())
        {
            st.push(x);
            minVal = x;
        }
        else if (x < minVal)
        {
            // encode
            st.push(2LL * x - minVal);
            minVal = x;
        }
        else
        {
            st.push(x);
        }
    }

    void pop()
    {
        if (st.empty())
            return;

        long long top = st.top();
        st.pop();

        if (top < minVal)
        {
            // decode previous min
            minVal = 2LL * minVal - top;
        }
    }

    int top()
    {
        if (st.empty())
            return -1;

        long long top = st.top();
        return (top < minVal) ? minVal : top;
    }

    int getMin()
    {
        if (st.empty())
            return -1;
        return minVal;
    }
};
