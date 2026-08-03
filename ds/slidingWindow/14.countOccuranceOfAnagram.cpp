class Solution
{
public:
    bool allZeros(vector<int> &counter)
    {
        for (int num : counter)
        {
            if (num != 0)
            {
                return false;
            }
        }
        return true;
    }
    int search(string &pat, string &txt)
    {
        // code here
        int k = pat.size();
        int n = txt.size();
        vector<int> counter(26, 0);
        for (int i = 0; i < k; i++)
        {
            char c = pat[i];
            counter[c - 'a']++;
        }

        int start = 0;
        int end = 0;
        int result = 0;

        while (end < n)
        {
            char ct = txt[end];
            counter[ct - 'a']--;

            if (end - start + 1 == k)
            {
                if (allZeros(counter))
                {
                    result++;
                }
                counter[txt[start] - 'a']++;
                start++;
            }
            end++;
        }
        return result;
    }
};