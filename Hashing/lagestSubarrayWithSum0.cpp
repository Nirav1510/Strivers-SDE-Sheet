#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int maxLen(vector<int> &v, int n)
    {
        int l = 0;
        int sum = 0;
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            sum += v[i];
            if (sum == 0)
            {
                l = i + 1;
            }
            else if (mp.count(sum))
            {
                l = max(l, i - mp[sum]);
            }
            else
            {
                mp[sum] = i;
            }
        }
        return l;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i)
        {
            cin >> array1[i];
        }
        Solution ob;
        cout << ob.maxLen(array1, m) << endl;
    }
    return 0;
}