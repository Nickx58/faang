class Solution
{
public:
    string minWindow(string s, string t)
    {
        vector<int> freq(128, 0);
        for (char c : t)
        {
            freq[c]++;
        }
        int minLength = INT_MAX;
        int startIndex = 0;

        int left = 0;
        int required = t.size();

        for (int right = 0; right < s.size(); right++)
        {
            char c = s[right];
            if (freq[c] > 0)
            {
                required--;
            }
            freq[c]--;
            while (required == 0)
            {
                if (right - left + 1 < minLength)
                {
                    minLength = right - left + 1;
                    startIndex = left;
                }
                freq[s[left]]++;
                if (freq[s[left]] > 0)
                {
                    required++;
                }
                left++;
            }
        }
        return minLength == INT_MAX ? "" : s.substr(startIndex, minLength);
    }
};