class Solution
{
public:
    vector<int> firstNegInt(vector<int> &arr, int k)
    {
        // code here
        queue<int> q;
        vector<int> res;

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] < 0)
            {
                q.push(i);
            }

            while (!q.empty() && q.front() <= i - k)
            {
                q.pop();
            }

            if (i >= k - 1)
            {
                if (!q.empty())
                {
                    int el = q.front();
                    res.push_back(arr[el]);
                }
                else
                {
                    res.push_back(0);
                }
            }
        }
        return res;
    }
};

class Solution
{
public:
    vector<int> firstNegInt(vector<int> &arr, int k)
    {
        // code here
        deque<int> q;
        vector<int> res;
        int i = 0;
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[j] < 0)
            {
                q.push_back(arr[j]);
            }

            if (j - i + 1 == k)
            {
                if (!q.empty())
                {
                    res.push_back(q.front());
                }
                else
                {
                    res.push_back(0);
                }

                if (arr[i] < 0 && !q.empty())
                {
                    q.pop_front();
                }
                i++;
            }
        }
        return res;
    }
};