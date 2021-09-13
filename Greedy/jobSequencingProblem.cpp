static bool compare(Job a, Job b)
{
    return a.profit > b.profit;
}

vector<int> JobScheduling(Job arr[], int n)
{
    sort(arr, arr + n, compare);

    int maxd = 0;
    for (int i = 0; i < n; i++)
    {
        maxd = max(maxd, arr[i].dead);
    }

    bool slot[maxd + 1] = {0};

    int job = 0, p = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].dead - 1; j >= 0; j--)
        {
            if (!slot[j])
            {
                slot[j] = 1;
                job++;
                p += arr[i].profit;
                break;
            }
        }
    }
    return {job, p};
}