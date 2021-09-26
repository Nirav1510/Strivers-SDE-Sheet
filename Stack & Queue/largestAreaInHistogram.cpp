#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    vector<long long> nsr(long long arr[], int n)
    {
        stack<long long> s;
        vector<long long> v(n);
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

    vector<long long> nsl(long long arr[], int n)
    {
        stack<long long> s;
        vector<long long> v(n);
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

    long long getMaxArea(long long arr[], int n)
    {
        vector<long long> right = nsr(arr, n);
        vector<long long> left = nsl(arr, n);

        vector<long long> width(n);
        long long area = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            width[i] = right[i] - left[i] - 1;
            area = max(area, width[i] * arr[i]);
        }
        return area;
    }
};

int main()
{
    long long t;

    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        long long arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.getMaxArea(arr, n) << endl;
    }
    return 0;
}