int findPlatform(int arr[], int dep[], int n)
{
    sort(arr, arr + n);
    sort(dep, dep + n);

    int res = 1;
    int plat = 1, i = 1, j = 0;

    while (i < n && j < n)
    {
        if (arr[i] <= dep[j])
        {
            plat++;
            i++;
        }
        else
        {
            plat--;
            j++;
        }
        res = max(res, plat);
    }
    return res;
}