// User function Template for C++
class Solution
{
public:
    bool areDisjoint(vector<int> &a, vector<int> &b)
    {
        // code here
        unordered_set<int> setA(a.begin(), a.end());

        for (int num : b)
        {
            if (setA.find(num) != setA.end())
            {
                return false;
            }
        }
        return true;
    }
};

// Given two arrays a[] and b[], check if they are disjoint, i.e.,
// there is no element common between both the arrays. Return true if if they are disjoint, otherwise, false.