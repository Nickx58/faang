#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (!(cin >> s))
        return 0;

    int n = s.length();
    int max_count = 1;
    int current_count = 1;

    for (int i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
        {
            current_count++;
            max_count = max(max_count, current_count);
        }
        else
        {
            current_count = 1;
        }
    }

    cout << max_count << endl;
    return 0;
}