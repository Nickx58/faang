class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> count;

        if (s.size() != t.size())
        {
            return false;
        }
        for (char ss : s)
        {
            count[ss]++;
        }

        for (char tt : t)
        {
            count[tt]--;
        }

        for (const auto &pair : count)
        {
            if (pair.second != 0)
            {
                return false;
            }
        }
        return true;
    }
};

// one more approach

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        int freq[26] = {0};

        for (char c : s)
            freq[c - 'a']++;

        for (char c : t)
            freq[c - 'a']--;

        for (int x : freq)
        {
            if (x != 0)
                return false;
        }

        return true;
    }
};