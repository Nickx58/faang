class Solution
{
public:
    int numOfSubarrays(vector<int> &arr, int k, int threshold)
    {
        int count = 0;
        int start = 0;
        int window_sum = 0;
        for (int end = 0; end < arr.size(); end++)
        {
            window_sum += arr[end];

            if (end - start + 1 > k)
            {
                window_sum -= arr[start];
                start++;
            }

            if (end - start + 1 == k)
            {
                int avg = window_sum / k;
                if (avg >= threshold)
                {
                    count++;
                }
            }
        }
        return count;
    }
};