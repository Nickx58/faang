#include <bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &arr, int start, int end) {
  if(start >= end) {
      return;
  }
  swap(arr[start],arr[end]);
  reverseArray(arr,start+1,end-1);
}

int main() {
    vector<int> arr = {1,2,3,4,5,6};
    int size = arr.size() - 1;
    reverseArray(arr,0,size);
    for(int i = 0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
