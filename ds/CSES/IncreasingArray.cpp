#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    long long moves = 0;
    long long current_max;

    cin >> current_max;

    for (int i = 1; i < n; i++)
    {
        long long x;
        cin >> x;

        if (x < current_max)
        {
            moves += (current_max - x);
        }
        else
        {
            current_max = x;
        }
    }

    cout << moves << endl;

    return 0;
}