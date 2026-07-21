class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int i = 0;
        int j = nums.size() - 1;
        vector<int> result(nums.size());
        int k = nums.size() - 1;

        while (k >= 0)
        {
            int a = nums[i] * nums[i];
            int b = nums[j] * nums[j];
            if (a > b)
            {
                result[k] = a;
                i++;
            }
            else
            {
                result[k] = b;
                j--;
            }
            k--;
        }
        return result;
    }
};