void solve(int i, vector<int> &ip, vector<int> &op, vector<vector<int>> &ans, int t)
{
    if (i == ip.size())
    {
        if (t == 0)
        {
            ans.push_back(op);
        }
        return;
    }
    if (ip[i] <= t)
    {
        op.push_back(ip[i]);
        solve(i, ip, op, ans, t - ip[i]);
        op.pop_back();
    }
    solve(i + 1, ip, op, ans, t);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<int> op;
    vector<vector<int>> ans;
    sort(candidates.begin(), candidates.end());
    solve(0, candidates, op, ans, target);
    return ans;
}