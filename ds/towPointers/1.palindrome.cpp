#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    string ss = "level";
    int start = 0;
    int end = ss.size() - 1;

    while (start < end)
    {
        if (ss[start] != ss[end])
        {
            cout << "Not pali";
            break;
        }
        start++;
        end--;
    }
}
