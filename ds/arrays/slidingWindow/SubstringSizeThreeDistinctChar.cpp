class Solution
{
public:
    int countGoodSubstrings(string s)
    {
        int left = 0;
        unordered_set<char> state;
        int count = 0;
        for (int right = 0; right < s.length(); right++)
        {
            while (state.count(s[right]))
            {
                state.erase(s[left]);
                left++;
            }
            state.insert(s[right]);

            if (right - left + 1 == 3)
            {
                count++;
                state.erase(s[left]);
                left++;
            }
        }
        return count;
    }
};