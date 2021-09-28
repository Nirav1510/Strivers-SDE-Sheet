#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<int> kLargest(int arr[], int n, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++)
        {
            pq.push(arr[i]);
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        vector<int> ans;
        while (!pq.empty())
        {
            ans.insert(ans.begin(), pq.top());
            pq.pop();
        }
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
