#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    string otp;
    for (char c : s)
    {
        if (c == '0' || c == '1')
        {
            otp += c;
        }
        else if (c == 'B')
        {
            if (!otp.empty())
            {
                otp.pop_back();
            }
        }
    }
    cout << otp;
}