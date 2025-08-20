#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;

        if (x > n)
        {
            cout << 0 << endl;
        }
        else
        {
            int diff = n - x;
            if (diff % 4 == 0)
            {
                cout << diff / 4 << endl;
            }
            else
            {
                int candies = (diff) / 4 + 1;
                cout << candies << endl;
            }
        }
    }
}
