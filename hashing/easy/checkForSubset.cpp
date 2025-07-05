class Solution
{
public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b)
    {
        // Your code here
        unordered_map<int, int> mp;

        for (int &num : a)
        {
            mp[num]++;
        }

        for (int &num : b)
        {
            if (mp[num] == 0)
            {
                return false;
            }
            mp[num]--;
        }
        return true;
    }
};

// Given two arrays a[] and b[], your task is to determine whether b[] is a subset of a[].