class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> hash;

        for (int i = 0; i < nums.size(); ++i)
        {
            int comps = target - nums[i];

            if (hash.find(comps) != hash.end())
            {
                return {hash[comps], i};
            }
            hash[nums[i]] = i;
        }
        return {};
    }
};