#include <bits/stdc++.h>
using namespace std;

// using extra space and maintaing the order.
int main()
{
    // your code goes here
    vector<int> arr = {8, 5, 10, 20};
    int n = arr.size();
    vector<int> zeroAtEnd;
    int countZeros = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            zeroAtEnd.push_back(arr[i]);
        }
        else
        {
            countZeros++;
        }
    }
    while (countZeros--)
    {
        zeroAtEnd.push_back(0);
    }

    for (int t : zeroAtEnd)
    {
        cout << t << " ";
    }
}

// without using extra space but not maintaing the order
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    vector<int> arr = {0, 0, 10, 0};
    int n = arr.size();
    int start = 0;
    int end = n - 1;
    while (start < end)
    {
        if (arr[start] != 0)
        {
            start++;
        }
        else if (arr[end] == 0)
        {
            end--;
        }
        else
        {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }
    for (int tt : arr)
    {
        cout << tt << " ";
    }
}

// best approach maintian the order and without extra space;
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    vector<int> arr = {8, 5, 0, 10, 0, 20};
    int n = arr.size();
    int insert = 0;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] != 0)
        {
            arr[insert] = arr[i];
            insert++;
        }
    }
    while (insert < n)
    {
        arr[insert] = 0;
        insert++;
    }
    for (int tt : arr)
    {
        cout << tt << " ";
    }
}
