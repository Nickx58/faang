#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    vector<int> arr = {2, 3, 5, 2, 9, 7, 1};
    int k = 3;
    vector<int> maxSum;

    for (int i = 0; i < arr.size() - k; i++)
    {
        int sum = 0;
        for (int j = i; j < i + k; j++)
        {
            sum += arr[j];
        }
        maxSum.push_back(sum);
    }
    for (int i = 0; i < maxSum.size(); i++)
    {
        cout << maxSum[i] << " ";
    }
}
