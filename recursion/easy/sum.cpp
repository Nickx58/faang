#include <bits/stdc++.h>
using namespace std;

int sum(int n) {
    if(n == 0) {
        return 0;
    }
    return n+sum(n-1);
}

void sum2(int n, int sum) {
    if(n < 1) {
        cout<<sum<<" ";
        return;
    }
    sum2(n-1,sum + n);
}
int main() {
    int num = 5;
    cout<<sum(num)<<endl;
    sum2(num,0);
}

// paramter way and function return way