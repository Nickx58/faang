class Solution
{
public:
    int mostFrequentElement(vector<int> &nums)
    {
        unordered_map<int, int> freq;

        // Count frequencies
        for (int num : nums)
        {
            freq[num]++;
        }

        int maxFreq = 0;
        int result = INT_MAX;

        for (auto &[num, count] : freq)
        {
            if (count > maxFreq)
            {
                maxFreq = count;
                result = num;
            }
            else if (count == maxFreq)
            {
                result = min(result, num);
            }
        }

        return result;
    }
};