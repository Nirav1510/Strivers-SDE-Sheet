#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    bool isPossible(int a[], int n, int m, int maxp)
    {
        int p = 1, sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += a[i];
            if (sum > maxp)
            {
                p++;
                sum = a[i];
            }
        }
        return p > m ? false : true;
    }

    int findPages(int a[], int n, int m)
    {
        if (n < m)
        {
            return -1;
        }
        int low = INT_MIN, high = 0;
        int ans = -1;
        for (int i = 0; i < n; i++)
        {
            high += a[i];
            low = max(low, a[i]);
        }

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (isPossible(a, n, m, mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
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
        int A[n];
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
