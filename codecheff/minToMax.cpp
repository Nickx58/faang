#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        // your code goes here
        int operations = 0;
        int min_value = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            min_value = min(a[i], min_value);
        }
        for (int i = 0; i < n; i++)
        {
            if (a[i] != min_value)
            {
                operations++;
            }
        }
        cout << operations << endl;
    }
}
