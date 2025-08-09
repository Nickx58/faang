#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;

    while (t--)
    {
        int x, y;
        cin >> x >> y;
        int count = 0;

        while (x >= y)
        {
            x -= y;
            count++;
        }
        count += x;
        cout << count << endl;
    }
}
