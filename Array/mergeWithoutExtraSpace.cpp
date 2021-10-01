// gap method O(n+m)log(m+n);
int newGap(int n)
{
    if (n <= 1)
    {
        return 0;
    }
    return (n / 2 + n % 2);
}

void merge(int a[], int b[], int n, int m)
{
    int gap = n + m;
    int i = 0, j = 0;
    while (gap)
    {
        for (i = 0; i + gap < n; i++)
        {
            if (a[i] > a[i + gap])
            {
                swap(a[i], a[i + gap]);
            }
        }
        for (j = (gap > n) ? gap - n : 0; i < n && j < m; i++, j++)
        {
            if (a[i] > b[j])
            {
                swap(a[i], b[j]);
            }
        }
        if (j < m)
        {
            for (j = 0; j + gap < m; j++)
            {
                if (b[j] > b[j + gap])
                {
                    swap(b[j], b[j + gap]);
                }
            }
        }
        gap = newGap(gap);
    }
}

// or

void merge(int a[], int b[], int n, int m)
{
    int i = n - 1, j = 0;

    while (i >= 0 && j < m)
    {
        if (a[i] > b[j])
        {
            swap(a[i], b[j]);
            i--;
            j++;
        }
        else
            break;
    }
    sort(a, a + n);
    sort(b, b + m);
}