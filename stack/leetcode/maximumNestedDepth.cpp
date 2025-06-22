class Solution
{
public:
    int maxDepth(string s)
    {
        int depth = 0;
        int currentMax = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                depth++;
            }
            if (s[i] == ')')
            {
                depth--;
            }
            currentMax = max(depth, currentMax);
        }
        return currentMax;
    }
};

// solve with stack later