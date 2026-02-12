class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int total_sum = 0;
        int n = cardPoints.size();
        for (int i = 0; i < n; i++)
        {
            total_sum += cardPoints[i];
        }
        if (k == n)
        {
            return total_sum;
        }
        int window_sum = 0;
        int minSum = 0;
        int window_size = n - k;
        for (int i = 0; i < window_size; i++)
        {
            window_sum += cardPoints[i];
        }

        minSum = window_sum;

        for (int i = window_size; i < n; i++)
        {
            window_sum += cardPoints[i] - cardPoints[i - window_size];
            minSum = min(minSum, window_sum);
        }
        return total_sum - minSum;
    }
};