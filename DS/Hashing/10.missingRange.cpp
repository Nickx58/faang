class Solution
{
public:
    vector<int> missinRange(vector<int> &arr, int low, int high)
    {
        // code here
        unordered_map<int, int> mp;
        for (int num : arr)
        {
            mp[num]++;
        }
        vector<int> result;
        for (int i = low; i <= high; i++)
        {
            if (mp[i] == 0)
            {
                result.push_back(i);
            }
        }
        return result;
    }
};

// Given an array arr[] of distinct integers and a range [low, high],
// find all the numbers within the range that are not present in the array. return the missing numbers in sorted order.