#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

class Solution
{
public:
    int MAH(int a[], int n)
    {
        int i, ans = 0;
        stack<int> s;
        vector<int> nsl(n), nsr(n);

        //finding nearest smaller to left
        for (i = 0; i < n; i++)
        {
            if (s.empty())
                nsl[i] = -1;
            else if (a[s.top()] < a[i])
                nsl[i] = s.top();
            else
            {
                while (!s.empty() && a[s.top()] >= a[i])
                    s.pop();
                if (s.empty())
                    nsl[i] = -1;
                else
                    nsl[i] = s.top();
            }
            s.push(i);
        }

        while (!s.empty())
            s.pop();

        // finding nearest smaller element to right
        for (i = n - 1; i >= 0; i--)
        {
            if (s.empty())
                nsr[i] = n;
            else if (a[s.top()] < a[i])
                nsr[i] = s.top();
            else
            {
                while (!s.empty() && a[s.top()] >= a[i])
                    s.pop();
                if (s.empty())
                    nsr[i] = n;
                else
                    nsr[i] = s.top();
            }
            s.push(i);
        }

        for (i = 0; i < n; i++)
            ans = max(ans, a[i] * (nsr[i] - nsl[i] - 1));
        return ans;
    }

    int maxArea(int a[MAX][MAX], int n, int m)
    {
        int temp[m] = {0}, ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                a[i][j] != 0 ? (temp[j] += a[i][j]) : (temp[j] = 0);

            ans = max(ans, MAH(temp, m));
        }
        return ans;
    }
};

int main()
{
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--)
    {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}