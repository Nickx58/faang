#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n, s;
        cin >> n >> s;

        int pizzas = ceil((double)(n * s) / 4);
        cout << pizzas << endl;
    }
}

// https://www.codechef.com/practice/course/logical-problems/DIFF800/problems/MINPIZZA