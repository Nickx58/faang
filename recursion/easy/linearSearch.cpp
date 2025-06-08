#include <bits/stdc++.h>
using namespace std;

int linearSearch(vector<int> arr, int target, int start, int end) {
    if(start > end) {
        return -1;
    }
    
    int element = arr[start];
    if(element == target) {
        return start;
    }
    return linearSearch(arr,target,start+1,end);
}

int main() {
    vector<int> arr = {1,2,3,4,5,6,8};
    int target = 5;
    int size = arr.size() - 1;
    int found = linearSearch(arr,target,0,size);
    cout<<found<<endl;
    return 0;
}
