class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int maxOnes = 0;
        int currentMaxOnes = 0;
        for (int x : nums)
        {
            if (x == 1)
            {
                currentMaxOnes++;
                maxOnes = max(maxOnes, currentMaxOnes);
            }
            else
            {
                currentMaxOnes = 0;
            }
        }
        return maxOnes;
    }
};