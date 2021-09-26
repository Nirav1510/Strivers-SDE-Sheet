#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        stack<int> s;

        int n = arr.size();
        vector<long long> ans(n, -1);

        for (int i = 2 * n - 1; i >= 0; i--)
        {

            while (s.size() > 0 && s.top() <= arr[i % n])
                s.pop();

            if (i < n)
            {
                if (!s.empty())
                    ans[i] = s.top();
            }
            s.push(arr[i % n]);
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

        int n;
        cin >> n;
        vector<long long> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution obj;
        vector<long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}