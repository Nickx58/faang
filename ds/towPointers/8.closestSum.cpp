using namespace std;

class Solution
{
public:
    int targetLimitedTwoSum(vector<int> &arr, int target)
    {
        sort(arr.begin(), arr.end());
        int start = 0;
        int end = arr.size() - 1;
        int closest = -1;
        int currentMax = -1;
        while (start < end)
        {
            int sum = arr[start] + arr[end];
            if (sum < target)
            {
                currentMax = sum;
                closest = max(closest, currentMax);
                start++;
            }
            else
            {
                end--;
            }
        }
        return closest;
    }
};