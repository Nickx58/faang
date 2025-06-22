class Solution
{
public:
    string clearDigits(string s)
    {
        stack<char> st;

        string newStr = "";

        for (auto &ch : s)
        {
            if (!isdigit(ch))
            {
                st.push(ch);
            }
            else
            {
                st.pop();
            }
        }
        while (!st.empty())
        {
            char c = st.top();
            newStr += c;
            st.pop();
        }

        reverse(newStr.begin(), newStr.end());
        return newStr;
    }
};