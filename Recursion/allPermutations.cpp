//with O(n) space

void solve(vector<int> &A, vector<int> &op, vector<int> &freq, vector<vector<int>> &ans)
{
    if (op.size() == A.size())
    {
        ans.push_back(op);
        return;
    }
    for (int i = 0; i < A.size(); i++)
    {
        if (!freq[i])
        {
            op.push_back(A[i]);
            freq[i] = 1;
            solve(A, op, freq, ans);
            freq[i] = 0;
            op.pop_back();
        }
    }
}

vector<vector<int>> Solution::permute(vector<int> &A)
{
    vector<vector<int>> ans;
    vector<int> op;
    int n = A.size();
    vector<int> freq(n, 0);
    solve(A, op, freq, ans);
    return ans;
}

// without extra space

void solve(int idx, vector<int> &nums, vector<vector<int>> &ans)
{
    if (idx == nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for (int i = idx; i < nums.size(); i++)
    {
        swap(nums[idx], nums[i]);
        solve(idx + 1, nums, ans);
        swap(nums[idx], nums[i]);
    }
    return;
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    solve(0, nums, ans);
    return ans;
}