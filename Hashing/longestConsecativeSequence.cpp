#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:

    int findLongestConseqSubseq(int a[], int n)
    {
        unordered_set<int> s;
        for (int i = 0; i < n; i++)
        {
            s.insert(a[i]);
        }

        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (s.find(a[i] - 1) == s.end())
            {
                int j = a[i] + 1;
                while (s.find(j) != s.end())
                {
                    j++;
                }
                ans = max(ans, j - a[i]);
            }
        }
        return ans;
    }
};

int main()
{
    int t, n, i, a[100001];
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.findLongestConseqSubseq(a, n) << endl;
    }

    return 0;
} 