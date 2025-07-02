class Solution
{
public:
    vector<int> applyOperations(vector<int> &nums)
    {
        for (int i = 0; i < nums.size() - 1; i++)
        {
            int index = i;
            int nextIndex = i + 1;
            if (nums[index] == nums[nextIndex])
            {
                nums[index] = 2 * nums[index];
                nums[nextIndex] = 0;
            }
        }
        int start = 0;
        int end = 0;
        while (end < nums.size())
        {
            if (nums[end] != 0)
            {
                swap(nums[start], nums[end]);
                start++;
            }
            end++;
        }
        return nums;
    }
};