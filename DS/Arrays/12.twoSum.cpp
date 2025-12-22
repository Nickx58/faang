/*
Two pointer approach will work if the array is sorted
If the array is not sorted there are two options:
    1. Sort the array but that will increase the time complexity
    2. Use the map solve it..
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> towSum(vector<int> arr, int target)
{
    vector<int> result;
    int start = 0;
    int end = arr.size() - 1;
    while (start <= end)
    {
        int sum = arr[start] + arr[end];
        if (sum == target)
        {
            result.push_back(start);
            result.push_back(end);
            break;
        }
        else if (sum < target)
        {
            start++;
        }
        else
        {
            end--;
        }
    }
    return result;
}
int main()
{
    // your code goes here
    vector<int> arr = {3, 3};
    int target = 6;

    vector result = towSum(arr, target);
    cout << result[0] << " " << result[1];
}
