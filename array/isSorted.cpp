#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    vector<int> arr = {5, 6, 12, 14, 15, 200};
    bool isSorted = true;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i + 1] < arr[i - 1])
        {
            isSorted = false;
            break;
        }
    }
    isSorted ? cout << "Sorted" : cout << "Not Sorted";
    return 0;
}
