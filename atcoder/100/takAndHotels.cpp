#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int n, k, x, y;
    cin >> n >> k >> x >> y;

    if (n <= k)
    {
        int price = n * x;
        cout << price << endl;
        return 0;
    }

    int y_days = n - k;
    int final_price = k * x + y_days * y;
    cout << final_price << endl;
    return 0;
}

// abc044 contests