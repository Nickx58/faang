#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    vector<int> a = {1, 2, 3, 4, 5};
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = i; j < a.size(); j++)
        {
            // print subaray from i to j
            for (int k = i; k <= j; k++)
            {
                cout << a[k] << " ";
            }
            cout << endl;
        }
    }
}
