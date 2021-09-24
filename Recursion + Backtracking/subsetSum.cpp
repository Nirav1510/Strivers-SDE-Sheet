#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(vector<int> &a, vector<int> &ans, int &s, int index)
    {
        if (index >= a.size())
        {
            ans.push_back(s);
            return;
        }
        solve(a, ans, s, index + 1);
        s += a[index];
        solve(a, ans, s, index + 1);
        s -= a[index];
    }

    vector<int> subsetSums(vector<int> a, int n)
    {
        vector<int> ans;
        int s = 0;
        solve(a, ans, s, 0);
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans)
        {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}