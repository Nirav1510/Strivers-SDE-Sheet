#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (a[j] < a[i] && dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main()
{
    //taking total testcases
    int t, n;
    cin >> t;
    while (t--)
    {
        
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
