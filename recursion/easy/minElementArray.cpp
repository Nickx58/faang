#include <bits/stdc++.h>
using namespace std;

int minElement(vector<int>arr,int size, int currentMin) {
    if(size < 0) {
        return currentMin;
    }
    if(arr[size] < currentMin) {
        currentMin = arr[size];
    }
    return minElement(arr,size-1,currentMin);
}
int getMin(vector<int>arr, int size) {
    int currentMin = INT_MAX;
    int min = minElement(arr,size,currentMin);
    return min;
}

int main() {
    vector<int> arr = {-11,3,-1,2,4};
    int size = arr.size();
    int min = getMin(arr,size);
    cout<<min;
}
