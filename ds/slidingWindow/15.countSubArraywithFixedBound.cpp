class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        long long ans = 0;
        int minKIndex = -1;
        int maxKIndex = -1;
        int cultIndex = -1;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < minK || nums[i] > maxK)
            {
                cultIndex = i;
            }
            if (nums[i] == minK)
            {
                minKIndex = i;
            }
            if (nums[i] == maxK)
            {
                maxKIndex = i;
            }
            long long smaller = min(maxKIndex, minKIndex);
            long long temp = smaller - cultIndex;
            ans += temp <= 0 ? 0 : temp;
        }
        return ans;
    }
};