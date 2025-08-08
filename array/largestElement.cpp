class Solution
{
public:
    int largestElement(vector<int> &nums)
    {
        int val = INT_MIN;

        for (int i = 0; i < nums.size(); i++)
        {
            val = max(val, nums[i]);
        }

        return val;
    }
};