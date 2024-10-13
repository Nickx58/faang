#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	vector<int> ans = {1,2,3,4,5};
	
    /*
        We have to swap the alternative elements
        Run the loop from 0 to n-1.
        Increment by 2
        Then swap the i and i+1 element
    */
	for(int i = 0; i<ans.size() - 1; i+= 2) {
	    swap(ans[i],ans[i+1]);
	}
	
	for(int i = 0; i<ans.size(); i++) {
	    cout<<ans[i]<<" ";
	}

}
