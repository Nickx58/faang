class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int left = 0;
        int maxLength = 0;
        unordered_map<char, int> seen;
        for (int right = 0; right < s.length(); right++)
        {
            char ch = s[right];
            if (seen.count(ch))
            {
                left = max(left, seen[ch] + 1);
            }
            seen[ch] = right;
            maxLength = max(maxLength, (right - left + 1));
        }
        return maxLength;
    }
};

int left = 0, right = 0;
int maxLength = 0;
unordered_set<char> seen;

while (right < s.length())
{
    if (!seen.count(s[right]))
    {
        seen.insert(s[right]);
        maxLength = max(maxLength, right - left + 1);
        right++;
    }
    else
    {
        seen.erase(s[left]);
        left++;
    }
}

return maxLength;