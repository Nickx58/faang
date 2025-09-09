#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

int main()
{
    int N;
    cin >> N;
    long long power = 1;
    for (int i = 1; i <= N; i++)
    {
        power = (power * i) % MOD;
    }
    cout << power << "\n";
    return 0;
}
