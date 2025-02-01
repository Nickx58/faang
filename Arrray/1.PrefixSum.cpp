#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int arr[] = {1,2,3,4,5};
	int size = sizeof(arr)/sizeof(arr[0]);
	int preFix[size];
	
	preFix[0] = arr[0];
	
	for(int i = 1; i<size; i++) {
	    preFix[i] = preFix[i-1] + arr[i];
	}
	
	for(int i = 0; i<size; i++) {
	    cout<<preFix[i]<<" ";
	}

}
