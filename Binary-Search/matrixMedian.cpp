int countSmallerThanMid(vector<int> &row, int mid)
{
    int l = 0, h = row.size() - 1;
    while (l <= h)
    {
        int m = l + (h - l) / 2;

        if (row[m] <= mid)
        {
            l = m + 1;
        }
        else
        {
            h = m - 1;
        }
    }
    return l;
}

int Solution::findMedian(vector<vector<int>> &a)
{
    int n = a.size(), m = a[0].size();
    int low = INT_MAX, high = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        low = min(low, a[i][0]);
    }
    for (int i = 0; i < n; i++)
    {
        high = max(high, a[i][m - 1]);
    }

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            count += countSmallerThanMid(a[i], mid);
        }
        if (count <= (n * m) / 2)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}
