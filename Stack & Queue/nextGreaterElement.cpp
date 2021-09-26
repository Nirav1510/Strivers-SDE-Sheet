#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        stack<long long> s;
        vector<long long> ans;

        for (int i = n - 1; i >= 0; i--)
        {
            if (s.empty())
            {
                ans.push_back(-1);
            }

            else if (s.size() > 0 && s.top() > arr[i])
            {
                ans.push_back(s.top());
            }

            else if (s.size() > 0 && s.top() <= arr[i])
            {

                while (s.size() > 0 && s.top() <= arr[i])
                    s.pop();

                if (s.empty())
                    ans.push_back(-1);
                else
                    ans.push_back(s.top());
            }
            s.push(arr[i]);
        }
        reverse(ans.begin(), ans.end());
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