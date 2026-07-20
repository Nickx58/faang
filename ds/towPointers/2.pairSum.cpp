#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Input: [1, 2, 3, 4, 6], target=6
    vector<int> nums = {1, 2, 3, 4, 6};
    int target = 6;

    int s = 0;
    int e = nums.size() - 1;

    while (s < e)
    {
        int sum = nums[s] + nums[e];
        if (sum == target)
        {
            cout << nums[s] << " " << nums[e];
            break;
        }
        else if (sum < target)
        {
            s++;
        }
        else
        {
            e--;
        }
    }
}
