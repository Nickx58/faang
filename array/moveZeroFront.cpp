#include <bits/stdc++.h>

using namespace std;

// this approach will change the order for non-zero elements
int main()
{
    vector<int> arr = {
        1,
        0,
        2,
        0,
        3,
        4,
        0};
    int n = arr.size();
    int start = 0;
    int end = n - 1;
    while (start < end)
    {
        if (arr[start] == 0)
        {
            start++;
        }
        else if (arr[end] != 0)
        {
            end--;
        }
        else if (arr[start] != 0 && arr[end] == 0)
        {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }
    for (int itt : arr)
    {
        cout << itt << " ";
    }
    return 0;
}

// approach to maintain the order of the elements;
int main2()
{
    // your code goes here
    vector<int> arr = {1, 2, 3, 4, 0, 0, 0};
    int n = arr.size();

    int index = n - 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] != 0)
        {
            arr[index] = arr[i];
            index--;
        }
    }
    while (index >= 0)
    {
        arr[index--] = 0;
    }
    for (int tt : arr)
    {
        cout << tt << " ";
    }
}
