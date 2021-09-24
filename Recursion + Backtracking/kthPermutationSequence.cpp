int fact(int n)
{
    int temp = 1;
    for (int i = 1; i < n; i++)
    {
        temp *= i;
    }
    return temp;
}

string getPermutation(int n, int k)
{
    vector<int> v;
    for (int i = 1; i <= n; i++)
    {
        v.push_back(i);
    }
    int f = fact(n);
    
    string ans = "";
    k = k - 1;

    while (!v.empty())
    {
        ans += to_string(v[k / f]);
        v.erase(v.begin() + k / f);
        if (v.size() == 0)
            break;
        k = k % f;
        f = f / v.size();
    }
    return ans;
}