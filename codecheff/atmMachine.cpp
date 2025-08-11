#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        int a[n];

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++)
        {
            int money = a[i];
            if (money <= k)
            {
                cout << 1;
                k = k - money;
            }
            else
            {
                cout << 0;
            }
        }
        cout << "\n";
    }
}
