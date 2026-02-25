#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    vector<int> arr = {100, 200, 300, 400};
    int n = arr.size();
    int k = 2;
    int sum = 0;

    for (int i = 0; i <= n - k; i++)
    {
        int current_sum = 0;
        for (int j = i; j < i + k; j++)
        {
            current_sum += arr[j];
        }
        sum = max(sum, current_sum);
    }

    cout << sum << " ";
}

// above is brute force problem
// below is sliding window

class Solution
{
public:
    int maxSubarraySum(vector<int> &arr, int k)
    {
        // code here
        int n = arr.size();
        int max_sum = 0;
        int window_sum = 0;

        for (int i = 0; i < k; i++)
        {
            window_sum += arr[i];
        }

        max_sum = window_sum;

        for (int i = k; i < n; i++)
        {
            window_sum += arr[i] - arr[i - k];
            max_sum = max(window_sum, max_sum);
        }
        return max_sum;
    }
};