#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int res = 0;
        while (n != 0)
        {
            int ld = n % 10;
            res = res * 10 + ld;
            n = n / 10;
        }
        cout << res << endl;
    }
}

/*
    Reverse a Number 1234
    1. Get the last digit -> by modulas n%10 -> give you last digit;
    2. set result to 0 and res*10 + ld;
        res = res * 10 + ld;
        This is the key step that builds the reversed number.
        You multiply the current result by 10 (to shift its digits left) and add the new digit.
        For example:
        First iteration: res = 0 * 10 + 4 = 4
        Second iteration (next digit is 3): res = 4 * 10 + 3 = 43
    3. Remove the last digit by n/10;
*/