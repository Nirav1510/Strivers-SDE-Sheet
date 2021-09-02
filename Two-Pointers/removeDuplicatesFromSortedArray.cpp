int removeDuplicates(vector<int> &v)
{
    int n = v.size(), j = 0;
    if (n <= 1)
    {
        return n;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (v[i] != v[i + 1])
        {
            v[j] = v[i];
            j++;
        }
    }
    v[j++] = v[n - 1];
    return j;
}