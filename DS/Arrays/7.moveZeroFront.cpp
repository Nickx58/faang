#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    vector<int> arr = {0, 1, 2, 0, 3, 0, 4, 0, 5, 6};
    int post = arr.size() - 1;

    for (int i = post; i >= 0; i--)
    {
        if (arr[i] != 0)
        {
            arr[post--] = arr[i];
        }
    }

    while (post >= 0)
    {
        arr[post--] = 0;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}
