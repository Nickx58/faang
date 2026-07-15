class Solution
{
public:
    vector<int> getConcatenation(vector<int> &nums)
    {
        int size = nums.size();
        vector<int> newArr(2 * size);
        for (int i = 0; i < size; i++)
        {
            newArr[i] = nums[i];
            newArr[i + size] = nums[i];
        }
        return newArr;
    }
};