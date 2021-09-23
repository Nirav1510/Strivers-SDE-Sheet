#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        // arr[] : int input array of integers
        // k : the quadruple sum required
        vector<vector<int>> fourSum(vector<int> &arr, int k)
        {
            sort(arr.begin(), arr.end());
            int n = arr.size();
            vector<vector<int>> ans;
            for (int i = 0; i < n - 1; i++)
            {

                for (int j = i + 1; j < n - 1; j++)
                {

                    int key = k - arr[i] - arr[j];
                    int left = j + 1, right = n - 1;

                    while (left < right)
                    {
                        int sum = arr[left] + arr[right];

                        if (sum == key)
                        {
                            vector<int> v(4, 0);
                            v[0] = arr[i];
                            v[1] = arr[j];
                            v[2] = arr[left];
                            v[3] = arr[right];

                            ans.push_back(v);

                            while (left < right && arr[left] == v[2])
                            {
                                ++left;
                            }
                            while (left < right && arr[right] == v[3])
                            {
                                --right;
                            }
                        }
                        else if (sum < key)
                        {
                            left++;
                        }
                        else
                        {
                            right--;
                        }
                    }
                    while (j < n - 1 && arr[j + 1] == arr[j])
                    {
                        ++j;
                    }
                }
                while (i < n - 1 && arr[i + 1] == arr[i])
                {
                    ++i;
                }
            }
            return ans;
        }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int>> ans = ob.fourSum(a, k);
        for (auto &v : ans)
        {
            for (int &u : v)
            {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty())
        {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}