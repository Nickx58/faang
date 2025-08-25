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

/*
    Count the digit.
    if you divide the number by 10 you will remove the last digit. while removing the last digit count the number of operation until number become 0
*/