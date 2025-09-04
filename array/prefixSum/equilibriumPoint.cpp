class Solution
{
public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr)
    {
        // code here
        int n = arr.size();

        vector<int> pref(n);
        vector<int> suf(n);

        pref[0] = arr[0];
        suf[n - 1] = arr[n - 1];

        for (int i = 1; i < n; i++)
        {
            pref[i] = pref[i - 1] + arr[i];
        }

        for (int i = n - 2; i >= 0; i--)
        {
            suf[i] = suf[i + 1] + arr[i];
        }

        for (int i = 0; i < n; i++)
        {
            if (pref[i] == suf[i])
            {
                return i;
            }
        }
        return -1;
    }
};