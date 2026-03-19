class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> mySet;

        for (int n : nums)
        {
            if (mySet.count(n))
            {
                return true;
            }
            mySet.insert(n);
        }
        return false;
    }
};