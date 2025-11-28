class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int index = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[index] != nums[i])
            {
                nums[index + 1] = nums[i];
                index++;
            }
        }
        return index + 1;
    }
};

/*
1st approach we can use the set data structures to store all the uniqye elements in the array
2nd use the two pointer technique as the array is sorted. Store all the unique element at the front-positions then return the index.
*/