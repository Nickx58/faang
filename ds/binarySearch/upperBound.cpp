#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    vector<int> nums = {1, 2, 3, 3, 5, 8, 8, 10, 10, 11};
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int ans = n;
    int x = 9;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        // maybe an answer
        if (nums[mid] > x)
        {
            ans = mid;
            high = mid - 1; // look for more small index on left
        }
        else
        {
            low = mid + 1; // look for right;
        }
    }

    cout << ans << " ";
}
