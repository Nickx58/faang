#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    vector<int> arr = {6, 5, 4, 3, 2, 1, 0};
    int low = 0;
    int high = arr.size() - 1;

    while (low < high)
    {
        swap(arr[low], arr[high]);
        low++;
        high--;
    }
    for (int num : arr)
    {
        cout << num << " ";
    }
    return 0;
}
