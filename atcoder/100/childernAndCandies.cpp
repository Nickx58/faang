#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int n;
    cin >> n;
    int sum = 0;
    while (n != 0)
    {
        sum += n;
        n--;
    }
    cout << sum;
}