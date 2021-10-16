#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void DFS(vector<vector<char>> &M, int i, int j, int ROW, int COL)
    {
        if (i < 0 || j < 0 || i > (ROW - 1) || j > (COL - 1) || M[i][j] != '1')
        {
            return;
        }

        if (M[i][j] == '1')
        {
            M[i][j] = '0';
            DFS(M, i + 1, j, ROW, COL);     //right side traversal
            DFS(M, i - 1, j, ROW, COL);     //left side traversal
            DFS(M, i, j + 1, ROW, COL);     //upward side traversal
            DFS(M, i, j - 1, ROW, COL);     //downward side traversal
            DFS(M, i + 1, j + 1, ROW, COL); //upward-right side traversal
            DFS(M, i - 1, j - 1, ROW, COL); //downward-left side traversal
            DFS(M, i + 1, j - 1, ROW, COL); //downward-right side traversal
            DFS(M, i - 1, j + 1, ROW, COL); //upward-left side traversal
        }
    }

    // Function to find the number of islands.
    int numIslands(vector<vector<char>> &M)
    {
        // Code here
        int ROW = M.size();
        int COL = M[0].size();
        int count = 0;
        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < COL; j++)
            {
                if (M[i][j] == '1')
                {
                    count++;
                    DFS(M, i, j, ROW, COL);
                }
            }
        }
        return count;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
} 