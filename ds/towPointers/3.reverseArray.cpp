#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> nums = {1, 2, 3, 4, 6};

    int s = 0;
    int e = nums.size() - 1;

    while (s < e)
    {
        swap(nums[s], nums[e]);
        s++;
        e--;
    }
    for (int x : nums)
    {
        cout << x << " ";
    }
}
