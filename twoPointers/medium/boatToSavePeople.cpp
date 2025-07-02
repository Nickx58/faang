class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        int count = 0;
        int start = 0;
        int end = people.size() - 1;
        sort(people.begin(), people.end());
        while (start <= end)
        {
            int sum = people[start] + people[end];
            if (sum <= limit)
            {
                count++;
                start++;
                end--;
            }
            else
            {
                end--;
                count++;
            }
        }
        return count;
    }
};