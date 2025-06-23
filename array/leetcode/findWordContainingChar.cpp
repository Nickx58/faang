class Solution
{
public:
    vector<int> findWordsContaining(vector<string> &words, char x)
    {
        vector<int> indexes;

        for (int i = 0; i < words.size(); i++)
        {
            string word = words[i];

            for (int j = 0; j < word.size(); j++)
            {
                if (word[j] == x)
                {
                    indexes.push_back(i);
                    break;
                }
            }
        }
        return indexes;
    }
};