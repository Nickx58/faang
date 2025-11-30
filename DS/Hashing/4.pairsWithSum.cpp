#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    vector<int> a = {8, 3, 4, 2, 5};
    int sum = 6;
    unordered_set<int> mySet;
    bool havePairs = false;
    for (int i = 0; i < a.size(); i++)
    {
        if (mySet.find(sum - a[i]) != mySet.end())
        {
            havePairs = true;
            break;
        }
        else
        {
            mySet.insert(a[i]);
        }
    }
    havePairs ? cout << "Found" : cout << "No Found";
}
