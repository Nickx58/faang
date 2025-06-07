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
