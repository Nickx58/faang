#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;

    while (t--)
    {
        int s, x, y, z;
        cin >> s >> x >> y >> z;

        int remaining_mem = s - (x + y);
        if (remaining_mem >= z)
        {
            cout << 0;
        }
        else
        {
            if (remaining_mem + x >= z || remaining_mem + y >= z)
            {
                cout << 1;
            }
            else
            {
                cout << 2;
            }
        }
        cout << "\n";
    }
}
