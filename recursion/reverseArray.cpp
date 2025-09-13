#include <bits/stdc++.h>
using namespace std;

void reverse(vector<int> &arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    swap(arr[start], arr[end]);
    reverse(arr, start + 1, end - 1);
}
int main()
{
    // your code goes here
    vector<int> arr = {6, 5, 4, 3, 2, 1};
    int size = arr.size();
    int start = 0;
    int end = size - 1;
    reverse(arr, start, end);
    for (int ii : arr)
    {
        cout << ii << " ";
    }
}
