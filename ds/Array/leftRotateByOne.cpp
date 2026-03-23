#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    vector<int> arr = {1, 2, 3, 4, 5, 6};

    int index = 0;
    int first = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        arr[index] = arr[i];
        index++;
    }

    int n = arr.size();
    arr[n - 1] = first;
    for (int m : arr)
    {
        cout << m << " ";
    }
}
