class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (int num : nums)
        {
            mp[num]++;
        }
        int el;
        int n = nums.size();
        int majority = n / 2;
        for (const auto &pair : mp)
        {
            if (pair.second > majority)
            {
                el = pair.first;
                break;
            }
        }
        return el;
    }
};

// optimized version
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int el = -1;
        int count = 0;

        for (int num : nums)
        {
            if (count == 0)
            {
                el = num;
                count = 1;
            }
            else if (num == el)
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        return el;
    }
};