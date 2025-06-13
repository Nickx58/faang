#include <bits/stdc++.h>
using namespace std;

int getArraySum(vector<int>arr, int size) {
    if(size < 0) {
        return 0;
    }
    int sum =  arr[size] + getArraySum(arr,size-1);
    return sum;
}

int main() {
    vector<int> arr = {1,2,3,4,5};
    int size = arr.size();
    int mean = getArraySum(arr, size);
    cout<<mean;
}
