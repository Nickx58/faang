class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int start = 0;             // 0
        int middle = 0;            // 1
        int end = nums.size() - 1; // 2

        while (middle <= end)
        {
            if (nums[middle] == 1)
            {
                middle++;
            }
            else if (nums[middle] == 0)
            {
                swap(nums[middle], nums[start]);
                start++;
                middle++;
            }
            else
            {
                swap(nums[middle], nums[end]);
                end--;
            }
        }
    }
};