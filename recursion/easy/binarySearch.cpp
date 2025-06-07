#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> arr, int target, int start, int end) {
    if(start > end) {
        return -1;
    }
    
    int mid = start + (end - start)/2;
    
    if(arr[mid] == target) {
        return mid;
    } else if(target > arr[mid]) {
        return binarySearch(arr,target,mid+1,end);
    } else {
        return binarySearch(arr,target,start,mid - 1);
    }
}
int main() {
    vector<int> arr = {1,2,3,44,55,66,77};
    int target = 77;
    int result = binarySearch(arr,target,0,arr.size() - 1);
    if(result == -1) {
        cout<<"Not found"<<endl;
    } else {
        cout<<"Element found at index: "<<result<<endl;
    }
}

/*
1. binarySearch(0, 6)
   → mid = 3 → arr[3] = 7 < 9 → search right
   → returns binarySearch(4, 6)

2. binarySearch(4, 6)
   → mid = 5 → arr[5] = 11 > 9 → search left
   → returns binarySearch(4, 4)

3. binarySearch(4, 4)
   → mid = 4 → arr[4] = 9 → FOUND → return 4

Now unwinding...

binarySearch(4, 4) returns **4** to
binarySearch(4, 6), which returns **4** to
binarySearch(0, 6), which returns **4** to main
*/


