#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    vector<int> arr = {30, 5, 20};
    int n = arr.size();
    int first = arr[0];
    int pos = 0;
    for (int i = 1; i < n; i++)
    {
        arr[pos] = arr[i];
        pos++;
    }
    arr[pos] = first;
    for (int tt : arr)
    {
        cout << tt << " ";
    }
}
