class Solution
{
public:
    string reversePrefix(string word, char ch)
    {
        bool found = false;
        int index = -1;
        for (int i = 0; i < word.size(); i++)
        {
            if (word[i] == ch)
            {
                index = i;
                found = true;
                break;
            }
        }
        if (!found)
        {
            return word;
        }

        int end = index;

        string str = "";

        for (int i = end; i >= 0; --i)
        {
            str += word[i];
        }

        for (int i = index + 1; i < word.size(); i++)
        {
            str += word[i];
        }
        return str;
    }
};

/*
current is also kind of optimized but we need to solve it with stack
*/