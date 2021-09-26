#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector<int> calculateSpan(int price[], int n)
    {
        stack<int> s;
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            if (s.empty())
                ans.push_back(-1);

            else if (s.size() > 0 && price[s.top()] > price[i])
            {
                ans.push_back(s.top());
            }
            else if (s.size() > 0 && price[s.top()] <= price[i])
            {
                while (s.size() > 0 && price[s.top()] <= price[i])
                {
                    s.pop();
                }
                if (s.empty())
                    ans.push_back(-1);
                else
                    ans.push_back(s.top());
            }
            s.push(i);
        }
        for (int i = 0; i < n; i++)
        {
            ans[i] = abs(i - ans[i]);
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
        int n;
        cin >> n;
        int i, a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        vector<int> s = obj.calculateSpan(a, n);

        for (i = 0; i < n; i++)
        {
            cout << s[i] << " ";
        }
        cout << endl;
    }
    return 0;
}