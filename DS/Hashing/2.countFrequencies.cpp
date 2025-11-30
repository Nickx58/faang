#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    vector<int> arr = {10, 12, 13, 10, 14, 12, 13, 14, 17, 17, 10};
    unordered_map<int, int> myMap;

    for (int i = 0; i < arr.size(); i++)
    {
        myMap[arr[i]]++;
    }

    for (auto it : myMap)
    {
        cout << it.first << " " << it.second << endl;
    }
}
