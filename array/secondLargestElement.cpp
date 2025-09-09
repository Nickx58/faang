#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    vector<int> arr = {20, 10, 20, 8, 1};

    int largest = 0;
    int second_largest = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > largest)
        {
            second_largest = largest;
            largest = arr[i];
        }
        else if (arr[i] > second_largest && arr[i] < largest)
        {
            second_largest = arr[i];
        }
    }
    if (second_largest == 0)
    {
        second_largest = -1;
    }
    cout << largest << " " << second_largest << endl;
}
