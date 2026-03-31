#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a = {1, 2, 3, 0, 0, 0};
    vector<int> b = {2, 5, 6};

    int m = 3; // valid elements in a
    int n = 3; // size of b

    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (i >= 0 && j >= 0)
    {
        if (a[i] > b[j])
        {
            a[k--] = a[i--];
        }
        else
        {
            a[k--] = b[j--];
        }
    }

    while (j >= 0)
    {
        a[k--] = b[j--];
    }

    for (int v : a)
    {
        cout << v << " ";
    }
}