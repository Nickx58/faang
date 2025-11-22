#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int del = 3;
    int index = 0;
    int size = sizeof(arr) / sizeof(int);

    // find the index to delete;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == del)
        {
            index = i;
        }
    }

    // we want to delete the 3;
    // index = 2;
    // loop from the index of element to delete till the end
    // arr[index] = arr[index+1];
    // return the size - 1;

    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    for (int i = 0; i < size - 1; i++)
    {
        cout << arr[i] << " ";
    }
}
