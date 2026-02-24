#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    vector<int> arr = {0, 1, 0, 1, 1, 0, 0, 1, 0};

    int left = 0;
    int right = arr.size() - 1;

    while (left < right)
    {
        if (arr[left] == 0)
        {
            left++;
        }
        else if (arr[right] == 1)
        {
            right--;
        }
        else
        {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }

    for (int num : arr)
    {
        cout << num << " ";
    }
}
