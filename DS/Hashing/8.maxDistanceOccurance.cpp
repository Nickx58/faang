#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {3, 2, 1, 2, 1, 4, 5, 8, 6, 7, 4, 2};

    unordered_map<int, int> firstIndex;
    int maxDifference = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (firstIndex.count(arr[i]))
        {
            maxDifference = max(maxDifference, i - firstIndex[arr[i]]);
        }
        else
        {
            firstIndex[arr[i]] = i;
        }
    }

    cout << maxDifference;
}

// max distance b/w two occurance