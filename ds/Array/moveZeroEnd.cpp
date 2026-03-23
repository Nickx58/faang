#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    vector<int> arr = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};

    int n = arr.size();
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            arr[index] = arr[i];
            index++;
        }
    }
    for (int i = index; i < n; i++)
    {
        arr[i] = 0;
    }

    for (int a : arr)
    {
        cout << a << " ";
    }
}

// tow pointer solution
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int start = 0;
        int size = nums.size();

        for (int fast = 0; fast < size; fast++)
        {
            if (nums[fast] != 0)
            {
                swap(nums[start], nums[fast]);
                start++;
            }
        }
    }
};