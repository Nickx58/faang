class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int el = -1;
        int count = 0;

        for (int x : nums)
        {
            if (count == 0)
            {
                count = 1;
                el = x;
            }
            else if (x == el)
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