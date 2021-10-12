long long maxProduct(vector<int> arr, int n)
{
    long long int ans = arr[0];
    long long int maxx = arr[0], minn = arr[0];

    for (long long int i = 1; i < n; i++)
    {
        long long int temp = arr[i];
        if (temp < 0)
        {
            swap(maxx, minn);
        }
        maxx = max(maxx * temp, temp);
        minn = min(minn * temp, temp);

        ans = max(maxx, ans);
    }
    return ans;
}