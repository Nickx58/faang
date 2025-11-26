#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    vector<int> arr = {100, 200, 300, 400, 500};

    bool sorted = true;

    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i + 1] < arr[i])
        {
            sorted = false;
            break;
        }
    }
    if (sorted)
    {
        cout << "Array is sorted";
    }
    else
    {
        cout << "Not Sorted";
    }
}
