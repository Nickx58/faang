#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    vector<int> arr = {1, 1, 2, 3, 3, 4, 4, 5, 5};
    // find number that appears only once

    int xor1 = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        xor1 = xor1 ^ arr[i];
    }

    cout << xor1 << endl;
}

// above is the best approach to solvce the problem. Optimal approach can be to use the hash map to store the freq
// but that will take extra space

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    vector<int> arr = {1, 1, 2, 3, 3, 4, 4, 5, 5};
    unordered_map<int, int> mp;

    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]]++;
    }

    for (auto it = mp.begin(); it != mp.end(); ++it)
    {
        if (it->second == 1)
        {
            cout << it->first << endl;
        }
    }
}
