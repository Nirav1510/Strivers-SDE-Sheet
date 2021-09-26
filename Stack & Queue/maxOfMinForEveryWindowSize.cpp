#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector<int> nsr(int arr[], int n)
    {
        stack<int> s;
        vector<int> v(n);
        for (int i = n - 1; i >= 0; i--)
        {
            if (s.empty())
            {
                v[i] = n;
            }
            else if (s.size() > 0 && arr[i] > arr[s.top()])
            {
                v[i] = s.top();
            }
            else if (s.size() > 0 && arr[i] <= arr[s.top()])
            {
                while (s.size() > 0 && arr[i] <= arr[s.top()])
                {
                    s.pop();
                }
                s.empty() ? v[i] = n : v[i] = s.top();
            }
            s.push(i);
        }
        return v;
    }

    vector<int> nsl(int arr[], int n)
    {
        stack<int> s;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            if (s.empty())
            {
                v[i] = -1;
            }
            else if (s.size() > 0 && arr[i] > arr[s.top()])
            {
                v[i] = s.top();
            }
            else if (s.size() > 0 && arr[i] <= arr[s.top()])
            {
                while (s.size() > 0 && arr[i] <= arr[s.top()])
                {
                    s.pop();
                }
                s.empty() ? v[i] = -1 : v[i] = s.top();
            }
            s.push(i);
        }
        return v;
    }

    vector<int> maxOfMin(int arr[], int n)
    {
        vector<int> right = nsr(arr, n);
        vector<int> left = nsl(arr, n);

        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++)
        {
            int len = right[i] - left[i] - 2;

            ans[len] = max(ans[len], arr[i]);
        }

        for (int i = n - 2; i >= 0; i--)
        {
            ans[i] = max(ans[i], ans[i + 1]);
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
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        vector<int> res = ob.maxOfMin(a, n);
        for (int i : res)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}