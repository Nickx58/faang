class Solution
{
public:
    int calPoints(vector<string> &operations)
    {
        stack<int> st;

        for (string i : operations)
        {
            if (i == "C")
            {
                st.pop();
            }
            else if (i == "D")
            {
                st.push(st.top() * 2);
            }
            else if (i == "+")
            {
                int val1 = st.top();
                st.pop();
                int val2 = st.top();
                int val3 = val1 + val2;
                st.push(val1);
                st.push(val3);
            }
            else
            {
                st.push(stoi(i));
            }
        }
        int sum = 0;
        while (!st.empty())
        {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};