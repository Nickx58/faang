#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;

    while (t--)
    {
        int a, b, c;
        int x, y, z;

        cin >> a >> b >> c >> x >> y >> z;

        int dragonMarks = a + b + c;
        int slothMarks = x + y + z;

        if (dragonMarks == slothMarks)
        { // both marks are same
            if (dragonMarks == slothMarks && a > x)
            {
                cout << "DRAGON";
            }
            else if (dragonMarks == slothMarks && a == x && b > y)
            {
                cout << "DRAGON";
            }
            else if (dragonMarks == slothMarks && x > a)
            {
                cout << "SLOTH";
            }
            else if (dragonMarks == slothMarks && x == a && y > b)
            {
                cout << "SLOTH";
            }
            else
            {
                cout << "TIE";
            }
        }
        else
        { // not same
            if (dragonMarks > slothMarks)
            {
                cout << "DRAGON";
            }
            else
            {
                cout << "SLOTH";
            }
        }
        cout << "\n";
    }
}

/* AI Solution */
{
    if (dragonMarks > slothMarks)
    {
        cout << "DRAGON" << endl;
    }
    else if (slothMarks > dragonMarks)
    {
        cout << "SLOTH" << endl;
    }
    else
    {
        // Total marks are equal, check DSA
        if (a > x)
        {
            cout << "DRAGON" << endl;
        }
        else if (x > a)
        {
            cout << "SLOTH" << endl;
        }
        else
        {
            // DSA marks are equal, check TOC
            if (b > y)
            {
                cout << "DRAGON" << endl;
            }
            else if (y > b)
            {
                cout << "SLOTH" << endl;
            }
            else
            {
                // TOC marks are equal, it's a tie
                cout << "TIE" << endl;
            }
        }
    }
}