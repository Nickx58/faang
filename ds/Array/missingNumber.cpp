#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 2, 4, 5, 6};

    int n = arr.size();
    int sumN = (n + 1) * (n + 2) / 2;

    int sum = 0;
    for (int nn : arr)
    {
        sum += nn;
    }

    cout << sumN - sum << " ";
}