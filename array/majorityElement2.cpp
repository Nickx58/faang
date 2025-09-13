class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int count1 = 0;
        int count2 = 0;
        int element1 = 0;
        int element2 = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (count1 == 0 && element2 != nums[i])
            {
                count1 = 1;
                element1 = nums[i];
            }
            else if (count2 == 0 && element1 != nums[i])
            {
                count2 = 1;
                element2 = nums[i];
            }
            else if (element1 == nums[i])
            {
                count1++;
            }
            else if (element2 == nums[i])
            {
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }

        vector<int> ans;
        int threshold = nums.size() / 3;
        count1 = 0;
        count2 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (element1 == nums[i])
            {
                count1++;
            }
            else if (element2 == nums[i])
            {
                count2++;
            }
        }
        if (count1 > threshold)
        {
            ans.push_back(element1);
        }
        if (count2 > threshold)
        {
            ans.push_back(element2);
        }
        return ans;
    }
};