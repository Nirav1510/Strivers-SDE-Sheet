// generating all subsets

void helper(int i, vector<int> &ip, vector<int> &op, vector<vector<int>> &ans)
{
    if (i == ip.size())
    {
        ans.push_back(op);
        return;
    }
    helper(i + 1, ip, op, ans);
    op.push_back(ip[i]);
    helper(i + 1, ip, op, ans);
    op.pop_back();
}

vector<vector<int>> subsetsWithDup(vector<int> &v)
{
    vector<int> op;
    vector<vector<int>> ans;
    sort(v.begin(), v.end());
    helper(0, v, op, ans);
    vector<vector<int>> res;
    map<vector<int>, int> m;
    for (int i = 0; i < ans.size(); i++)
    {
        if (m[ans[i]] == 0)
        {
            m[ans[i]]++;
            res.push_back(ans[i]);
        }
    }
    return res;
}

// without map

void solve(vector<int> &nums, vector<vector<int>> &res, vector<int> &ds, int ind)
{
    res.push_back(ds);
    for (int i = ind; i < nums.size(); i++)
    {
        if (i != ind && nums[i] == nums[i - 1])
            continue;
        ds.push_back(nums[i]);
        solve(nums, res, ds, i + 1);
        ds.pop_back(); 
    }
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<vector<int>> res;
    vector<int> ds;
    sort(nums.begin(), nums.end());
    solve(nums, res, ds, 0);
    return res;
}