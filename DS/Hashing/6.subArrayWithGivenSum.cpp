#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    vector<int> arr = {5, 3, 2, -1};
    int sum = 4;
    unordered_set<int> s;
    int pref_sum = 0;
    bool found = false;
    for (int i = 0; i < arr.size(); i++)
    {
        pref_sum += arr[i];
        if (pref_sum == sum)
        {
            found = true;
            break;
        }
        if (s.find(pref_sum - sum) != s.end())
        {
            found = true;
            break;
        }
        s.insert(pref_sum);
    }
    found ? cout << "Found" : cout << "Not Found";
}
