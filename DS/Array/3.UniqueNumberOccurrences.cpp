/*
Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.
*/

bool isUniqueOccurrences(vector<int>& arr) {
    unordered_map<int,int> ans;

    // store the freq;

    for(int i = 0; i<arr.size(); i++) {
        int key = arr[i];
        ans[key]++;
    }

    // set to store the unique occurrences
    set<int>freq;

    /*
        we are looping in the map and storing the element in the set. Because set store only unique element
        While storing we are checking if that element is exist in the set or not. 
        If exit then we return false from the function
        else we store it in the set
        After the loop we return true indicating the unique occurrence of the elements frequency.
    */
    for(auto it: ans) {
        if(freq.find(it.second) != freq.end()) {
            return false;
        }
        freq.insert(it.second);
    }
    return true;
}

