class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> pref;
        int count = 0;
        int sum = 0;
        pref[0] = 1;

        for (int num : nums)
        {
            sum += num;

            if (pref.find(sum - k) != pref.end())
            {
                count += pref[sum - k];
            }

            pref[sum]++;
        }
        return count;
    }
};