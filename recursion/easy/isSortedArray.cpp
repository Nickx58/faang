#include <bits/stdc++.h>
using namespace std;

bool isSorted(vector<int> arr, int start, int end) {
    if(start >= end) {  // Base case: reached the end
        return true;
    }

    if(arr[start] > arr[start + 1]) {
        return false;
    }

    return isSorted(arr, start + 1, end);
}

int main() {
    vector<int> arr = {1, 3, 4, 15, 17, 19, 111};
    int size = arr.size() - 1;  // Pass last index, not full size
    cout << isSorted(arr, 0, size);
    return 0;
}
