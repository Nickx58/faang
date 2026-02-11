class Solution
{
public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        long long maxSum = 0;
        long long window_sum = 0;

        unordered_map<int, int> freq;

        int left = 0;

        for (int right = 0; right < nums.size(); right++)
        {
            window_sum += nums[right];
            freq[nums[right]]++;

            while (freq[nums[right]] > 1 || right - left + 1 > k)
            {
                window_sum -= nums[left];
                freq[nums[left]]--;
                left++;
            }

            if (right - left + 1 == k)
            {
                maxSum = max(maxSum, window_sum);
            }
        }
        return maxSum;
    }
};