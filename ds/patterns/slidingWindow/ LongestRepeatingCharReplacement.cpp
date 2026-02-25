class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int maxi = 0;
        int start = 0;
        unordered_map<char, int> freq;
        int maxFreq = 0;

        for (int end = 0; end < s.length(); end++)
        {
            freq[s[end]]++;
            maxFreq = max(maxFreq, freq[s[end]]);
            while ((end - start + 1) - maxFreq > k)
            {
                freq[s[start]]--;
                start++;
            }
            maxi = max(maxi, end - start + 1);
        }

        return maxi;
    }
};