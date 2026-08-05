class Solution
{
public:
    bool isVowel(char c)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            return true;
        }
        return false;
    }
    int maxVowels(string s, int k)
    {
        int maxCount = INT_MIN;
        int count = 0;
        int l = 0;
        for (int r = 0; r < s.size(); r++)
        {
            if (isVowel(s[r]))
            {
                count++;
            }
            if (r - l + 1 > k)
            {
                if (isVowel(s[l]))
                {
                    count--;
                }
                l++;
            }
            if (r - l + 1 == k)
            {
                maxCount = max(maxCount, count);
            }
        }
        return maxCount;
    }
};