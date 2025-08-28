class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        double sum = 0;

        for (int i = 0; i < k; i++)
        {
            sum += nums[i];
        }

        double maxSum = sum;

        for (int i = k; i < nums.size(); i++)
        {
            sum += nums[i] - nums[i - k];
            maxSum = max(maxSum, sum);
        }
        return maxSum / k;
    }
};
/*
k = 3;
5,2,-1,0,3;
first linear loop -> 5+2 - 1 = 6;
sum = 6;

2nd Loop
maxSum = sum
i = 3, 3<5; i++;
sum += num[i] - num[i-k];
sum = 6 + 0 - 5
sum = 1;
maxSum = max(maxSum, sum) -> 6;

i = 4; 4<5; i++
sum = 1 + 4 - 2
sum = 3;
maxSum = max(maxSum, sum) => 6
Ans -> 6;
*/