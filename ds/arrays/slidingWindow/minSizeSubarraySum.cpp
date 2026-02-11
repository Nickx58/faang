class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int size = INT_MAX;
        int window_sum = 0;

        int left = 0;

        for (int right = 0; right < nums.size(); right++)
        {
            window_sum += nums[right];

            while (window_sum >= target)
            {
                size = min(size, right - left + 1);
                window_sum -= nums[left];
                left++;
            }
        }
        return size == INT_MAX ? 0 : size;
    }
};