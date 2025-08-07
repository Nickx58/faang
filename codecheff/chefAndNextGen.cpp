#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, x, y;
        cin >> a >> b >> x >> y;

        x *y >= a *b ? cout << "Yes" : cout << "No";
        cout << endl;
    }
}
