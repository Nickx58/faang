#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    vector<int> zeros = {0, 1, 2, 0, 3, 0, 4, 0, 5, 6};
    // {1,2,3,4,5,6,0,0,0};

    int position = 0;
    for (int i = 0; i < zeros.size(); i++)
    {
        if (zeros[i] != 0)
        {
            zeros[position++] = zeros[i];
        }
    }

    for (int i = position; i < zeros.size(); i++)
    {
        zeros[i] = 0;
    }

    for (int i = 0; i < zeros.size(); i++)
    {
        cout << zeros[i] << " ";
    }
}
