#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, l;
    cin >> n >> l;
    vector<string> arr;
    while (n--)
    {
        string a;
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    string con;
    for (string s : arr)
    {
        con += s;
    }
    cout << con << endl;
    return 0;
}

// abc 042 B problem