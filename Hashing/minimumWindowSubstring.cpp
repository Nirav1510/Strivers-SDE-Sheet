#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow(string s, string p)
    {
        int mp[256] = {0};
        int count = 0;
        for (int i = 0; i < p.length(); i++)
        {
            if (mp[p[i]] == 0)
                count++;

            mp[p[i]]++;
        }
        int start = 0, i = 0, j = 0, res = INT_MAX;
        while (j < s.length())
        {
            mp[s[j]]--;

            if (mp[s[j]] == 0)
                count--;

            if (count == 0)
            {
                while (count == 0)
                {
                    if (res > j - i + 1)
                    {
                        res = j - i + 1;
                        start = i;
                    }
                    mp[s[i]]++;
                    if (mp[s[i]] > 0)
                        count++;

                    i++;
                }
            }
            j++;
        }

        return (res == INT_MAX) ? "-1" : s.substr(start, res);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        string pat;
        cin >> pat;
        Solution obj;
        cout << obj.smallestWindow(s, pat) << endl;
    }
    return 0;
}