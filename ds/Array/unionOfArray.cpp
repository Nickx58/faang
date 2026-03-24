#include <bits/stdc++.h>

using namespace std;

int main()
{
    // your code goes here
    vector<int> arr1 = {
        1,
        1,
        2,
        3,
        4,
        5,
        7};
    vector<int> arr2 = {
        2,
        3,
        4,
        4,
        5,
        6};
    int n1 = arr1.size();
    int n2 = arr2.size();
    int i = 0;
    int j = 0;
    vector<int> un;

    while (i < n1 && j < n2)
    {
        if (arr1[i] <= arr2[j])
        {
            if (un.size() == 0 || un.back() != arr1[i])
            {
                un.push_back(arr1[i]);
            }
            i++;
        }
        else
        {
            if (un.size() == 0 || un.back() != arr2[j])
            {
                un.push_back(arr2[j]);
            }
            j++;
        }
    }

    while (i < n1)
    {
        if (un.size() == 0 || un.back() != arr1[i])
        {
            un.push_back(arr1[i]);
        }
        i++;
    }
    while (j < n2)
    {
        if (un.size() == 0 || un.back() != arr2[j])
        {
            un.push_back(arr2[j]);
        }
        j++;
    }

    for (int n : un)
    {
        cout << n << " ";
    }
}