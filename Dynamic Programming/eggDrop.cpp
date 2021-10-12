#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int dp[201][201];
    int solve(int e, int f)
    {
        if (e == 1 || f <= 1)
            return f;

        if (dp[e][f] != -1)
            return dp[e][f];
        int ans = INT_MAX;
        int low = 1, high = f;
        while (low < high)
        {
            int left, right;
            int mid = low + (high - low) / 2;

            dp[e - 1][mid - 1] != -1 ? left = dp[e - 1][mid - 1] : left = solve(e - 1, mid - 1);
            dp[e][f - mid] != -1 ? right = dp[e][f - mid] : right = solve(e, f - mid);
            int temp = 1 + max(left, right);

            if (left < right)
                low = mid + 1;
            else
                high = mid - 1;

            ans = min(ans, temp);
        }
        return dp[e][f] = ans;
    }

    int eggDrop(int e, int f)
    {
        memset(dp, -1, sizeof(dp));
        return solve(e, f);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        cout << ob.eggDrop(n, k) << endl;
    }
    return 0;
}