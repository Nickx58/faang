class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int maxi = 0;
        for (int i = 0; i < s.length(); i++)
        {
            unordered_set<char> mySet;
            for (int j = i; j < s.length(); j++)
            {
                if (mySet.count(s[j]))
                {
                    break;
                }
                mySet.insert(s[j]);
                maxi = max(maxi, j - i + 1);
            }
        }
        return maxi;
    }
};
// above brute force
// below sliding window

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int maxi = 0;
        int i = 0;
        int j = 0;
        unordered_set<char> mySet;
        while (j < s.length())
        {
            while (mySet.count(s[j]))
            {
                mySet.erase(s[i]);
                i = i + 1;
            }
            mySet.insert(s[j]);
            maxi = max(maxi, (j - i) + 1);
            j = j + 1;
        }
        return maxi;
    }
};