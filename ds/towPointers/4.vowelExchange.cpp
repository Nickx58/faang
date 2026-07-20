using namespace std;

class Solution
{
public:
    bool isVowel(char c)
    {
        c = tolower(c);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            return true;
        }
        return false;
    }
    string vowelExchange(string s)
    {
        int start = 0;
        int end = s.size() - 1;

        while (start < end)
        {
            if (!isVowel(s[start]))
            {
                start++;
            }
            else if (!isVowel(s[end]))
            {
                end--;
            }
            else
            {
                if (isVowel(s[start]) && isVowel(s[end]))
                {
                    swap(s[start], s[end]);
                    start++;
                    end--;
                }
            }
        }
        return s;
    }
};