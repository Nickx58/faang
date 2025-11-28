class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int size = nums.size();
        k = k % size; // To handle cases where k > size

        // Reverse the first k elements
        reverse(nums.begin(), nums.begin() + k);

        // Reverse the remaining elements
        reverse(nums.begin() + k, nums.end());

        // Reverse the entire array
        reverse(nums.begin(), nums.end());
    }
};
