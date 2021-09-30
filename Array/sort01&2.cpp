#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void sort012(int A[], int n)
    {
        int i = 0, j = 0, k = n - 1;
        while (j <= k)
        {
            if (A[j] == 0)
                swap(A[i++], A[j]);
            if (A[j] == 2)
                swap(A[j], A[k--]);
            else
                j++;
        }
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
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}