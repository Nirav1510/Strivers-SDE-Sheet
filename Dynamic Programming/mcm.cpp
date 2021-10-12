#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
class Solution
{
    public:
    int dp[101][101];
    int solve(int arr[], int i, int j)
    {
        if (i >= j)
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int mn = INT_MAX;
        for (int k = i + 1; k <= j; k++)
        {
            int temp = solve(arr, i, k - 1) + solve(arr, k, j) + arr[i - 1] * arr[k - 1] * arr[j];
            mn = min(mn, temp);
        }
        return dp[i][j] = mn;
    }

    int matrixMultiplication(int n, int arr[])
    {

        memset(dp, -1, sizeof(dp));
        int ans = solve(arr, 1, n - 1);

        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.matrixMultiplication(N, arr) << endl;
    }
    return 0;
} 