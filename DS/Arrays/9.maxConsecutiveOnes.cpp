#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    vector<int> arr = {0, 1, 1, 2, 3, 1, 9, 0, 3, 4, 5, 6};
    // max consecutive ones in array;

    int ones = 0;
    int maxOnes = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 1)
        {
            ones++;
            maxOnes = max(maxOnes, ones);
        }
        else
        {
            ones = 0;
        }
    }
    cout << maxOnes << endl;
}
