bool isPalindrome(string str)
{
    int i = 0, j = str.size() - 1;
    while (i < j)
    {
        if (str[i] != str[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

void solve(string &s, vector<string> &op, vector<vector<string>> &res)
{
    if (s.size() == 0)
    {
        res.push_back(op);
        return;
    }

    for (int j = 0; j < s.size(); j++)
    {
        string first = s.substr(0, j + 1);
        string second = s.substr(j + 1, s.size() - j);
        if (isPalindrome(first))
        {
            op.push_back(first);
            solve(second, op, res);
            op.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> res;
    vector<string> op;
    solve(s, op, res);
    return res;
}