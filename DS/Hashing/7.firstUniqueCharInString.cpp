#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    string s = "loveleetcode";
    map<char, int> mp;
    vector<char> index;
    for (char c : s)
    {
        mp[c]++;
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (mp[s[i]] == 1)
        {
            cout << i << endl;
            break;
        }
    }
}