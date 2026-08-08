class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        int start = 0;
        int end = 0;
        int window_sum = 0;
        int max_sum = INT_MIN;

        while (end < nums.size())
        {
            window_sum += nums[end];

            while (end - start + 1 > k)
            {
                window_sum -= nums[start];
                start++;
            }
            if (end - start + 1 == k)
            {
                max_sum = max(max_sum, window_sum);
            }
            end++;
        }
        return (double)max_sum / k;
    }
};