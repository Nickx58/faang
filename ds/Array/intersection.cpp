#include <bits/stdc++.h>

using namespace std;

int main()
{
    // your code goes here
    vector<int> arr1 = {1, 2, 2, 3, 3, 4, 5, 6, 7};
    vector<int> arr2 = {2, 3, 3, 5, 6, 6, 7};
    int n = arr1.size();
    int m = arr2.size();
    int i = 0;
    int j = 0;
    vector<int> inter;

    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else if (arr2[j] < arr1[i])
        {
            j++;
        }
        else
        {
            inter.push_back(arr1[i]);
            i++;
            j++;
        }
    }

    for (int aa : inter)
    {
        cout << aa << " ";
    }
}