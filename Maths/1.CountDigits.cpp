#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int num;
    cin >> num;
    int res = 0;

    while (num > 0)
    {
        num = num / 10;
        res++;
    }
    cout << res;
}
