class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int start = 0;
        int maxFruits = 0;
        unordered_map<int, int> baskets;

        for (int end = 0; end < fruits.size(); end++)
        {
            baskets[fruits[end]]++;

            while (baskets.size() > 2)
            {
                baskets[fruits[start]]--;
                if (baskets[fruits[start]] == 0)
                {
                    baskets.erase(fruits[start]);
                }
                start++;
            }
            maxFruits = max(maxFruits, end - start + 1);
        }
        return maxFruits;
    }
};