#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int dp[501][501];
    bool isPal(string s, int i, int j)
    {
        if (i >= j)
            return true;
        while (i < j)
        {
            if (s[i++] != s[j--])
            {
                return false;
            }
        }
        return true;
    }

    int solve(string s, int i, int j)
    {
        if (i > j)
            return 0;

        if (isPal(s, i, j))
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = INT_MAX;
        for (int k = i; k < j; k++)
        {
            int left, right;
            dp[i][k] != -1 ? left = dp[i][k] : left = solve(s, i, k);
            dp[k + 1][j] != -1 ? right = dp[k + 1][j] : right = solve(s, k + 1, j);

            int temp = 1 + left + right;
            ans = min(ans, temp);
        }
        return dp[i][j] = ans;
    }

    int palindromicPartition(string str)
    {
        memset(dp, -1, sizeof(dp));
        int res = solve(str, 0, str.size() - 1);
        return res;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;

        Solution ob;
        cout << ob.palindromicPartition(str) << "\n";
    }
    return 0;
} 