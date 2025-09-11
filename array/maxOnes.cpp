#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    vector<int> arr = {1, 0, 1, 1, 1, 1, 0, 1, 1};
    int n = arr.size();
    int maxOne = 0;
    int current_count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            current_count++;
            maxOne = max(maxOne, current_count);
        }
        else
        {
            current_count = 0;
        }
    }
    cout << maxOne << endl;
}
