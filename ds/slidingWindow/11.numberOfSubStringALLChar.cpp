class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int len = s.length();
        int left = 0;
        int right = 0;
        int total = 0;

        vector<int> freq(3, 0);

        while (right < len)
        {
            char ch = s[right];
            freq[ch - 'a']++;

            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0)
            {
                total += len - right;

                char lefChar = s[left];
                freq[lefChar - 'a']--;
                left++;
            }
            right++;
        }
        return total;
    }
};