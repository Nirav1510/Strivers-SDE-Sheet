bool isSafe(int r, int c, vector<string> &mat)
{
    int rr = r;
    int cc = c;

    //check for upper diagonal
    while (r >= 0 && c >= 0)
    {
        if (mat[r--][c--] == 'Q')
        {
            return false;
        }
    }
    r = rr, c = cc;
    //check for left side
    while (c >= 0)
    {
        if (mat[r][c--] == 'Q')
        {
            return false;
        }
    }

    c = cc;

    //check for lower diagonal
    while (c >= 0 && r < mat.size())
    {
        if (mat[r++][c--] == 'Q')
        {
            return false;
        }
    }
    return true;
}

void solve(int col, vector<string> &mat, vector<vector<string>> &ans)
{
    if (col == mat.size())
    {
        ans.push_back(mat);
        return;
    }

    for (int row = 0; row < mat.size(); row++)
    {
        if (isSafe(row, col, mat))
        {
            mat[row][col] = 'Q';
            solve(col + 1, mat, ans);
            mat[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> mat(n);
    string s(n, '.');
    for (int i = 0; i < n; i++)
    {
        mat[i] = s;
    }
    solve(0, mat, ans);
    return ans;
}