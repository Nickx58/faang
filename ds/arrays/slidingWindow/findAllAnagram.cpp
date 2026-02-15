class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> result;
        vector<int> p_freq(26, 0);
        vector<int> s_freq(26, 0);
        int m = s.size();
        int n = p.size();

        if (n > m)
        {
            return {};
        }

        for (char c : p)
        {
            p_freq[c - 'a']++;
        }

        int i = 0;
        int j = 0;

        while (j < m)
        {
            s_freq[s[j] - 'a']++;

            if (j - i + 1 > n)
            {
                s_freq[s[i] - 'a']--;
                i++;
            }
            if (s_freq == p_freq)
            {
                result.push_back(i);
            }
            j++;
        }
        return result;
    }
};