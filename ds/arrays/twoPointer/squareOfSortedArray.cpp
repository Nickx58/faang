class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        int position = n - 1;
        vector<int> result(n);
        while (start <= end)
        {
            int leftValue = abs(nums[start]);
            int rightValue = abs(nums[end]);

            if (leftValue > rightValue)
            {
                result[position] = leftValue * leftValue;
                start++;
            }
            else
            {
                result[position] = rightValue * rightValue;
                end--;
            }
            position--;
        }
        return result;
    }
};