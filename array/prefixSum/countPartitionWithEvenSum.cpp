class Solution
{
public:
    int countPartitions(vector<int> &nums)
    {
        int count = 0;
        int n = nums.size();

        vector<int> pref(n);
        pref[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            pref[i] = pref[i - 1] + nums[i];
        }

        for (int i = 0; i < n - 1; i++)
        {
            int minusCurrentSum = pref[i] + pref[i];
            int sumDiff = abs(pref[n - 1] - minusCurrentSum);
            if (sumDiff % 2 == 0)
            {
                count++;
            }
        }
        return count == 0 ? 0 : count;
    }
};

// Leetcode: 3432. Count Partitions with Even Sum Difference