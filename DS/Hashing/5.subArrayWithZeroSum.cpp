#include <bits/stdc++.h>
using namespace std;

bool isSubArrayWithZeroSum(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        int current_sum = 0;
        for (int j = i; j < arr.size(); j++)
        {
            current_sum += arr[j];
            if (current_sum == 0)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    // your code goes here
    vector<int> arr = {5, 6, 0, 7};
    bool found = isSubArrayWithZeroSum(arr);
    if (found)
    {
        cout << "Found";
    }
    else
    {
        cout << "Not Found";
    }
}

// O(n2) solution

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    vector<int> arr = {5, 6};
    unordered_set<int> s;
    int pref_sum = 0;
    bool found = false;
    for (int i = 0; i < arr.size(); i++)
    {
        pref_sum += arr[i];
        if (pref_sum == 0)
        {
            found = true;
            break;
        }
        if (s.find(pref_sum) != s.end())
        {
            found = true;
            break;
        }
        s.insert(pref_sum);
    }
    found ? cout << "Found" : cout << "Not";
}
