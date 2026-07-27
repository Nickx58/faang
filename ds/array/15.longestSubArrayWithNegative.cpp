class Solution
{
public:
    int longestSubarray(vector<int> &arr, int k)
    {
        // code here
        int n = arr.size();
        unordered_map<long long, int> mp;

        int maxi = 0;
        long long sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += arr[i];

            if (sum == k)
            {
                maxi = i + 1;
            }
            if (mp.find(sum - k) != mp.end())
            {
                maxi = max(maxi, i - mp[sum - k]);
            }
            if (mp.find(sum) == mp.end())
            {
                mp[sum] = i;
            }
        }
        return maxi;
    }
};