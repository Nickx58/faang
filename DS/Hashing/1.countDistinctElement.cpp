#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    vector<int> arr = {15, 12, 13, 12, 13, 13, 18};
    unordered_set<int> mySet;

    for (int i = 0; i < arr.size(); i++)
    {
        mySet.insert(arr[i]);
    }

    cout << mySet.size() << " ";
}
