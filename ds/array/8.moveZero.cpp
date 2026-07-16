class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int nonZeros = 0;
        for (int x : nums)
        {
            if (x != 0)
            {
                nums[nonZeros] = x;
                nonZeros++;
            }
        }
        for (int i = nonZeros; i < nums.size(); i++)
        {
            nums[i] = 0;
        }
    }
};