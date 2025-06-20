class Solution
{
public:
    vector<int> finalPrices(vector<int> &prices)
    {
        vector<int> final;

        for (int i = 0; i < prices.size(); i++)
        {
            bool found = false;
            for (int j = i + 1; j < prices.size(); j++)
            {
                if (prices[j] <= prices[i])
                {
                    int price = prices[i] - prices[j];
                    final.push_back(price);
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                final.push_back(prices[i]);
            }
        }
        return final;
    }
};

/*
Above solution is without stack. Need to find a solution with stack.
*/