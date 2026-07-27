class Solution
{
public:
    int longestSubarray(vector<int> &arr, int k)
    {
        // code here
        int left = 0;
        int right = 0;
        long long sum = arr[0];
        int maxi = 0;

        int n = arr.size();
        while (right < n)
        {
            while (left <= right && sum > k)
            {
                sum -= arr[left];
                left++;
            }
            if (sum == k)
            {
                maxi = max(maxi, right - left + 1);
            }
            right++;
            if (right < n)
            {
                sum += arr[right];
            }
        }
        return maxi;
    }
};