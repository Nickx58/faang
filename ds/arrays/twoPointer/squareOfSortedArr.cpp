class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int start = 0;
        int n = nums.size();
        int end = nums.size() - 1;
        int position = nums.size() - 1;
        vector<int> result(n, 0);
        while (start <= end)
        {
            int leftVal = abs(nums[start]);
            int rightVal = abs(nums[end]);

            if (leftVal > rightVal)
            {
                result[position] = leftVal * leftVal;
                start++;
            }
            else
            {
                result[position] = rightVal * rightVal;
                end--;
            }
            position--;
        }
        return result;
    }
};