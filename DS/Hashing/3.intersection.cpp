#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    vector<int> a = {10, 20, 30};
    vector<int> b = {10, 30, 40};
    unordered_set<int> mySet;

    for (int i = 0; i < b.size(); i++)
    {
        mySet.insert(b[i]);
    }

    for (int i = 0; i < a.size(); i++)
    {
        if (mySet.find(a[i]) != mySet.end())
        {
            cout << a[i] << " ";
        }
    }
}

// intersection of array which distinct elements and order need to be same as array first;