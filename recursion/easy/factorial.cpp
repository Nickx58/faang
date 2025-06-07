#include <bits/stdc++.h>
using namespace std;

int facto(int n) {
    if(n <= 1) {
        return 1;
    }
    return n*facto(n-1);
}
int main() {
    int num = 5;
    cout<<facto(num);
}
