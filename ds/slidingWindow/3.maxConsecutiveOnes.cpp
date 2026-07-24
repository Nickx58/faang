class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int left = 0;
        int right = 0;
        int size = nums.size();
        int maxiLength = 0;
        int zeros = 0;
        while (right < size)
        {
            if (nums[right] == 0)
            {
                zeros++;
            }
            while (zeros > k)
            {
                if (nums[left] == 0)
                {
                    zeros--;
                }
                left++;
            }
            maxiLength = max(maxiLength, right - left + 1);
            right++;
        }
        return maxiLength;
    }
};