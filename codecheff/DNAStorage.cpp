#include <bits/stdc++.h>

using namespace std;

vector<string> splitString(string s, int n, vector<string> &ss)
{
    vector<string> result;
    int j = 0;
    string res;
    while (j < n)
    {
        res += s[j];
        if (res.size() == 2)
        {
            result.push_back(res);
            res = "";
        }
        j++;
    }
    return result;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<string> ss;
        ss = splitString(s, n, ss);
        string newStr;
        for (int i = 0; i < ss.size(); i++)
        {
            if (ss[i] == "00")
            {
                newStr += "A";
            }
            else if (ss[i] == "01")
            {
                newStr += "T";
            }
            else if (ss[i] == "10")
            {
                newStr += "C";
            }
            else
            {
                newStr += "G";
            }
        }
        cout << newStr << "\n";
    }
}