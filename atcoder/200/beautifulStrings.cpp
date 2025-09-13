#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    unordered_map<char, int> mp;
    for (char c : s)
    {
        mp[c]++;
    }
    for (auto p : mp)
    {
        if (p.second % 2 != 0)
        {
            cout << "No" << "\n";
            return 0;
        }
    }
    cout << "Yes" << "\n";
    return 0;
}

// abc 044 b