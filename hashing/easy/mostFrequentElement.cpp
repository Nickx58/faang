// You are given an integer array arr[].You need to return the element which occurs maximum times in arr[].
// Note : If multiple such elements exists return the maximum element.

class Solution
{
public:
    int mostFreqEle(vector<int> &arr)
    {
        // code here
        unordered_map<int, int> mp;
        int maxi = INT_MIN;

        for (int &num : arr)
        {
            mp[num]++;
        }
        int maxEl = arr[0];
        for (auto it : mp)
        {
            if (it.second > maxi)
            {
                maxi = it.second;
                maxEl = it.first;
            }
            else if (it.second == maxi && it.first > maxEl)
            {
                maxEl = it.first;
            }
        }
        return maxEl;
    }
};