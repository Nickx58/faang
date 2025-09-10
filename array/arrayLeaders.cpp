class Solution
{
public:
    vector<int> leaders(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> leaders;
        int current_leader = arr[n - 1]; // Use last element
        leaders.push_back(current_leader);

        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i] >= current_leader)
            {
                leaders.push_back(arr[i]);
                current_leader = arr[i];
            }
        }

        reverse(leaders.begin(), leaders.end());
        return leaders;
    }
};
