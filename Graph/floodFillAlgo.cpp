#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int n, m;
    void dfs(vector<vector<int>> &img, int sr, int sc, int newC, int prev)
    {
        if (sr < 0 || sr > n - 1 || sc < 0 || sc > m - 1 || img[sr][sc] == newC || img[sr][sc] != prev)
            return;

        img[sr][sc] = newC;
        dfs(img, sr + 1, sc, newC, prev);
        dfs(img, sr - 1, sc, newC, prev);
        dfs(img, sr, sc + 1, newC, prev);
        dfs(img, sr, sc - 1, newC, prev);
    }

    vector<vector<int>> floodFill(vector<vector<int>> &img, int sr, int sc, int newClr)
    {
        n = img.size(), m = img[0].size();
        dfs(img, sr, sc, newClr, img[sr][sc]);
        return img;
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
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans)
        {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }
    }
    return 0;
}