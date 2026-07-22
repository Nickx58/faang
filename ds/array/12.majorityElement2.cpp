class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int count1 = 0;
        int count2 = 0;
        int el1 = 0;
        int el2 = 0;

        for (int x : nums)
        {
            if (count1 == 0 && el2 != x)
            {
                count1++;
                el1 = x;
            }
            else if (count2 == 0 && el1 != x)
            {
                count2++;
                el2 = x;
            }
            else if (x == el1)
            {
                count1++;
            }
            else if (x == el2)
            {
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }

        int threshold = nums.size() / 3;
        int c1 = 0;
        int c2 = 0;
        for (int x : nums)
        {
            if (x == el1)
            {
                c1++;
            }
            else if (x == el2)
            {
                c2++;
            }
        }
        vector<int> result;
        if (c1 > threshold)
        {
            result.push_back(el1);
        }
        if (c2 > threshold)
        {
            result.push_back(el2);
        }
        return result;
    }
};