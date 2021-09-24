void solve(int i, vector<int> &ip, vector<int> &op, vector<vector<int>> &ans, int t)
{
    if (t == 0)
    {
        ans.push_back(op);
        return;
    }
    for (int j = i; j < ip.size(); j++)
    {
        if (j > i && ip[j] == ip[j - 1])
            continue;
        if (ip[j] > t)
            break;
        op.push_back(ip[j]);
        solve(j + 1, ip, op, ans, t - ip[j]);
        op.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<int> op;
    vector<vector<int>> ans;
    sort(candidates.begin(), candidates.end());
    solve(0, candidates, op, ans, target);
    return ans;
}