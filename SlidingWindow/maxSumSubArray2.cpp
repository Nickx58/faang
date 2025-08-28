#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    vector<int> nums = {1, 2, 3, 4, 5};
    int x = 11;

    int sum = 0;
    int maxSum = INT_MIN;
    int left = 0;
    for (int right = 0; right < nums.size(); ++right)
    {
        sum += nums[right];

        while (sum > x && left <= right)
        {
            sum -= nums[left];
            left++;
        }
        if (sum <= x)
        {
            maxSum = max(maxSum, sum);
        }
    }
    cout << maxSum << endl;
}
