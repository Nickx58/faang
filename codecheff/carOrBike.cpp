#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;

    while (t--)
    {
        int bike, car;
        cin >> bike >> car;

        if (car > bike)
        {
            cout << "BIKE";
        }
        else if (bike > car)
        {
            cout << "CAR";
        }
        else
        {
            cout << "SAME";
        }
        cout << "\n";
    }
}
