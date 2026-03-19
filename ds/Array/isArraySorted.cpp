#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {2, 3, 33, 111, 113, 1000};
    bool is_sorted = true;

    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i + 1] < arr[i])
        {
            is_sorted = false;
            break;
        }
    }

    cout << is_sorted << " ";
}