class Solution
{
public:
    string strSort(string s)
    {
        int counter[26] = {0};
        for (char c : s)
        {
            counter[c - 'a']++;
        }
        string t;
        for (int i = 0; i < 26; i++)
        {
            t += string(counter[i], i + 'a');
        }
        return t;
    }
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> result;

        for (string s : strs)
        {
            mp[strSort(s)].push_back(s);
        }

        for (auto p : mp)
        {
            result.push_back(p.second);
        }
        return result;
    }
};