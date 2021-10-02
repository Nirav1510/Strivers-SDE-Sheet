#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool isSubsetSum(int n, int arr[], int sum)
    {
        int dp[n + 1][sum + 1];

        for (int j = 0; j < sum + 1; j++)
        {
            dp[0][j] = 0;
        }
        for (int i = 0; i < n + 1; i++)
        {
            dp[i][0] = 1;
        }

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < sum + 1; j++)
            {
                if (arr[i - 1] <= j)
                {
                    dp[i][j] = (dp[i - 1][j - arr[i - 1]]) || (dp[i - 1][j]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][sum];
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, sum;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        cin >> sum;

        Solution ob;
        cout << ob.isSubsetSum(N, arr, sum) << endl;
    }
    return 0;
}