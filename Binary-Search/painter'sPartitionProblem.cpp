#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
    public:
        bool isValid(int a[], int n, int k, ll mid)
        {
            ll p = 1, sum = 0;
            for (int i = 0; i < n; i++)
            {
                sum += a[i];
                if (sum > mid)
                {
                    p++;
                    sum = a[i];
                }
            }
            return !(p > k);
        }

        long long minTime(int a[], int n, int k)
        {
            ll low = 0, high = 0;
            for (int i = 0; i < n; i++)
            {
                low = max(low, (ll)a[i]);
                high += a[i];
            }
            ll ans = -1;
            while (low <= high)
            {
                ll mid = low + (high - low) / 2;

                if (isValid(a, n, k, mid))
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
        int k, n;
        cin >> k >> n;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        cout << obj.minTime(arr, n, k) << endl;
    }
    return 0;
} 