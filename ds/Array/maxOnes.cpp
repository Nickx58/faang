#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 1, 1, 1, 0, 1, 1};
    int maxOnes = INT_MIN;
    int current_count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 1)
        {
            current_count += 1;
            maxOnes = max(current_count, maxOnes);
        }
        else
        {
            current_count = 0;
        }
    }
    cout << maxOnes << " ";
}