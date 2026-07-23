class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int leftSum = 0;
        int rightSum = 0;
        int maxSum = 0;
        int n = cardPoints.size() - 1;
        int rightIndex = n;

        for (int i = 0; i < k; i++)
        {
            leftSum += cardPoints[i];
        }
        maxSum = leftSum;
        for (int i = k - 1; i >= 0; i--)
        {
            leftSum -= cardPoints[i];
            rightSum += cardPoints[rightIndex];
            rightIndex--;
            maxSum = max(maxSum, leftSum + rightSum);
        }
        return maxSum;
    }
};