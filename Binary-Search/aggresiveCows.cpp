#include <bits/stdc++.h>
using namespace std;

bool isPossible(int a[], int n, int cows, int minDist)
{
    int cntCows = 1;
    int lastPlacedCow = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] - lastPlacedCow >= minDist)
        {
            cntCows++;
            lastPlacedCow = a[i];
        }
    }
    return (cntCows < cows) ? false : true;
}

int solve(int dis[], int n, int c)
{
    int low = 1, high = dis[n - 1] - dis[0];
    int res = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (isPossible(dis, n, c, mid))
        {
            res = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, cows;
        cin >> n >> cows;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);

        cout << solve(a, n, cows) << endl;
    }
    return 0;
}