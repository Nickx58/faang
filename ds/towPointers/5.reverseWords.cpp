using namespace std;

// Input: s = "This is a string"
// Output: "sihT si a gnirts"
// Explanation: All the words of the given string are reversed.

class Solution
{
public:
    void reverseStr(int start, int end, string &s)
    {
        while (start < end)
        {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
    string reverseWords(string s)
    {
        int start = 0;
        int size = s.size();
        int end = 0;

        while (end < size)
        {
            if (s[end] == ' ')
            {
                reverseStr(start, end - 1, s);
                start = end + 1;
            }
            end++;
        }
        reverseStr(start, size - 1, s);
        return s;
    }
};