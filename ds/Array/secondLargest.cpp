#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {2, 3, 33, 111, 111, 10};

    int largest = INT_MIN;
    int second_largest = INT_MIN;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > largest)
        {
            second_largest = largest;
            largest = arr[i];
        }
        else if (arr[i] > second_largest && arr[i] != largest)
        {
            second_largest = arr[i];
        }
    }

    cout << largest << " " << second_largest;
}