#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int maximumPath(int n, vector<vector<int>> mat)
    {
        int dp[n][n];
        for (int j = 0; j < n; j++)
            dp[0][j] = mat[0][j];

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {

                if (j == 0)
                {
                    dp[i][j] = mat[i][j] + max(dp[i - 1][j + 1], dp[i - 1][j]);
                }
                else if (j == n - 1)
                {
                    dp[i][j] = mat[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
                }
                else
                {
                    dp[i][j] = mat[i][j] + max({dp[i - 1][j + 1], dp[i - 1][j], dp[i - 1][j - 1]});
                }
            }
        }
        return *max_element(dp[n - 1], dp[n - 1] + n);
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
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for (int i = 0; i < N * N; i++)
            cin >> Matrix[(i / N)][i % N];

        Solution ob;
        cout << ob.maximumPath(N, Matrix) << "\n";
    }
    return 0;
}