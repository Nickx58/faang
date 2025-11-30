#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    vector<int> arr = {1, 2, 3, 4, 5, 7};

    int n = arr.size();

    int missingNumber = 0;

    for (int i = 1; i <= n; i++)
    {
        bool flag = false;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == i)
            {
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            missingNumber = i;
        }
    }
    cout << missingNumber << endl;
}

/*
time complexity O(n)2 space is O(1)
better approach will be use the hashing.
Store all the element in the hasing array with default value to 0;
While iterating from 1 - N marking the freq of element 1;
On the second iteration the element that is not marked or with zero freq
that will be the missing number
Time and space will be O(n) + O(n) and space O(n);
*/

// best approach XOR and Sum

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    vector<int> arr = {1, 2, 3, 4, 6, 7};

    int n = arr.size();

    int xor1 = 0;
    int xor2 = 0;

    for (int i = 0; i < n - 1; i++)
    {
        xor2 = xor2 ^ arr[i];
        xor1 = xor1 ^ (i + 1);
    }

    xor1 = xor1 ^ n;
    cout << (xor1 ^ xor2);
}
