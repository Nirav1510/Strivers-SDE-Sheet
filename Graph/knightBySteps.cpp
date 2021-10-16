int Solution::knight(int n, int m, int c, int d, int e, int f)
{
    int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
    int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};
    int count = 0;
    queue<pair<int, int>> q;
    int ki = c, kj = d;
    q.push({ki, kj});

    bool vis[n + 1][m + 1];
    memset(vis, 0, sizeof(vis));

    vis[ki][kj] = 1;

    while (!q.empty())
    {
        int sz = q.size();
        while (sz--)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == e && y == f)
                return count;

            for (int k = 0; k < 8; k++)
            {
                int l = x + dx[k];
                int r = y + dy[k];
                if (l >= 1 && l <= n && r >= 1 && r <= m && !vis[l][r])
                {
                    vis[l][r] = true;
                    q.push({l, r});
                }
            }
        }
        count++;
    }
    return -1;
}