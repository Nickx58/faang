#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, h, c;

        cin >> a >> b >> h >> c;
        if (a == b)
        {
            cout << "Yes";
        }
        else if (a < b)
        {
            int temp = a + h;
            if (temp >= b)
            {
                cout << "Yes";
            }
            else
            {
                cout << "No";
            }
        }
        else
        {
            int temp = a - c;
            if (temp <= b)
            {
                cout << "Yes";
            }
            else
            {
                cout << "No";
            }
        }
        cout << "\n";
    }
}
