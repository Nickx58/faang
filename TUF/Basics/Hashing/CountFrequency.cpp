class Solution
{
public:
    vector<vector<int>> countFrequencies(vector<int> &nums)
    {
        // Your code goes here
        vector<vector<int>> result;

        unordered_map<int, int> hp;

        for (int i = 0; i < nums.size(); i++)
        {
            hp[nums[i]]++;
        }

        for (auto &it : hp)
        {
            result.push_back({it.first, it.second});
        }
        return result;
    }
};