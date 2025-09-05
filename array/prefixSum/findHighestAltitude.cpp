class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        int n = gain.size();
        vector<int> pref(n + 1);

        pref[0] = 0;
        pref[1] = gain[0];

        for (int i = 2; i <= n; i++)
        {
            pref[i] = pref[i - 1] + gain[i - 1];
        }

        int maxi = INT_MIN;
        for (int i = 0; i < pref.size(); i++)
        {
            maxi = max(maxi, pref[i]);
        }

        return maxi;
    }
};

// 1732. Find the Highest Altitude