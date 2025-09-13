#include <bits/stdc++.h>
using namespace std;

void fn(int n)
{
    if (n == 0)
    {
        return;
    }
    fn(n - 1);
    cout << n << endl;
}
int main()
{
    // your code goes here
    int n;
    cin >> n;
    fn(n);
}
