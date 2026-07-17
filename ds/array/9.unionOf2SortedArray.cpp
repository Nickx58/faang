#include <bits/stdc++.h>

using namespace std;

int main()
{
    // your code goes here
    vector<int> a = {
        1,
        1,
        2,
        3,
        4,
        5};
    vector<int> b = {
        2,
        3,
        4,
        4,
        5,
        6};
    vector<int> c;

    int i = 0;
    int j = 0;

    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
        {
            if (c.empty() || c.back() != a[i])
            {
                c.push_back(a[i]);
            }
            i++;
        }
        else if (b[j] < a[i])
        {
            {
                if (c.empty() || c.back() != b[j])
                {
                    c.push_back(b[j]);
                }
                j++;
            }
        }
        else
        {
            if (c.empty() || c.back() != a[i])
            {
                c.push_back(a[i]);
            }
            i++;
            j++;
        }
    }
    while (i < a.size())
    {
        if (c.empty() || c.back() != a[i])
        {
            c.push_back(a[i]);
        }
        i++;
    }
    while (j < b.size())
    {
        if (c.empty() || c.back() != b[j])
        {
            c.push_back(b[j]);
        }
        j++;
    }
    for (int x : c)
    {
        cout << x << " ";
    }
}