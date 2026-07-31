class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        vector<int> s1_freq(26, 0);
        vector<int> s2_freq(26, 0);

        int left = 0;
        int right = 0;

        for (char c : s1)
        {
            int idx = c - 'a';
            s1_freq[idx]++;
        }
        int window_size = s1.size();
        while (right < s2.size())
        {
            s2_freq[s2[right] - 'a']++;
            if (right - left + 1 > window_size)
            {
                s2_freq[s2[left] - 'a']--;
                left++;
            }
            if (s1_freq == s2_freq)
            {
                return true;
            }
            right++;
        }

        return false;
    }
};