class Solution
{
public:
    int minPairSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int maxSum = 0;
        int start = 0;
        int end = nums.size() - 1;

        while (start < end)
        {
            int sum = nums[start] + nums[end];
            maxSum = max(sum, maxSum);
            start++;
            end--;
        }
        return maxSum;
    }
};