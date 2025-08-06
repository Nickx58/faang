#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, y;
        cin >> n >> x >> y;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int initial_sum = 0;
        for (int i = 0; i < n; i++)
        {
            initial_sum += a[i];
        }
        int cost_with_discount = 0;
        for (int i = 0; i < n; i++)
        {
            if (y <= a[i])
            {
                int dis = a[i] - y;
                cost_with_discount += dis;
            }
        }
        int final_cost = cost_with_discount + x;
        if (final_cost < initial_sum)
        {
            cout << "COUPON";
        }
        else
        {
            cout << "NO COUPON";
        }
        cout << endl;
    }
}
