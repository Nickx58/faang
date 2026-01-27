class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int start = 0;
        int size = nums.size();

        for (int fast = 0; fast < size; fast++)
        {
            if (nums[fast] != 0)
            {
                swap(nums[start], nums[fast]);
                start++;
            }
        }
    }
};