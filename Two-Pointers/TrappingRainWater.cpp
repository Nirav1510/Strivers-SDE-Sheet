// space = O(n)

int trap(vector<int> &height)
{
    int n = height.size();
    int res = 0;
    int lmax[n], rmax[n];
    lmax[0] = height[0];
    for (int i = 1; i < n; i++)
    {
        lmax[i] = max(lmax[i - 1], height[i]);
    }
    rmax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        rmax[i] = max(rmax[i + 1], height[i]);
    }
    for (int i = 1; i < n - 1; i++)
    {
        res += (min(lmax[i], rmax[i]) - height[i]);
    }
    return res;
}

// space = O(1)

int trap(vector<int> &h)
{
    int res = 0;

    int lmax = 0, rmax = 0, i = 0, j = h.size() - 1;

    while (i < j)
    {

        if (h[i] <= h[j])
        {

            if (h[i] >= lmax)
            {
                lmax = h[i];
            }
            else
            {
                res += (lmax - h[i]);
            }
            i++;
        }
        else
        {

            if (h[j] >= rmax)
            {
                rmax = h[j];
            }
            else
            {
                res += (rmax - h[j]);
            }
            j--;
        }
    }
    return res;
}