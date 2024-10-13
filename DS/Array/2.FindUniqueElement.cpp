#include <bits/stdc++.h>
using namespace std;

/*
    This solution use a additional ds map to store the frequency of each element
    Firstly we are looping over array to store the frequencey of each element
    Secondly we are looping over map to check if element has a frequency 1.
    then we priting that element with one freq.
*/
int main() {
	// your code goes here
	vector<int> ans = {2,3,1,6,3,6,2,1,5};
	unordered_map<int,int> mp;
	
	for(int i = 0; i<ans.size(); i++) {
	    mp[ans[i]]++;
	}
	
	for(const auto& pair: mp) {
	    if(pair.second == 1) {
	        cout<<pair.first<<endl;
	    }
	}
	

}

/*
    second solution to use the bitwise xor
    xor of same element will give the answer 0;
    4^4 = 0
    0^5 = 5;
*/
{

    int findUnique(int *arr, int size) {
        int ans = 0;
        for(int i = 0; i<size; i++) {
            ans = ans ^ arr[i];
        }
        return ans;
    }

}